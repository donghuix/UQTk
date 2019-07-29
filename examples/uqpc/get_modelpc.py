#!/usr/bin/env python
#=====================================================================================
#                     The UQ Toolkit (UQTk) version @UQTKVERSION@
#                     Copyright (@UQTKYEAR@) Sandia Corporation
#                     http://www.sandia.gov/UQToolkit/
#
#     Copyright (@UQTKYEAR@) Sandia Corporation. Under the terms of Contract DE-AC04-94AL85000
#     with Sandia Corporation, the U.S. Government retains certain rights in this software.
#
#     This file is part of The UQ Toolkit (UQTk)
#
#     UQTk is free software: you can redistribute it and/or modify
#     it under the terms of the GNU Lesser General Public License as published by
#     the Free Software Foundation, either version 3 of the License, or
#     (at your option) any later version.
#
#     UQTk is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU Lesser General Public License for more details.
#
#     You should have received a copy of the GNU Lesser General Public License
#     along with UQTk.  If not, see <http://www.gnu.org/licenses/>.
#
#     Questions? Contact Bert Debusschere <bjdebus@sandia.gov>
#     Sandia National Laboratories, Livermore, CA, USA
#=====================================================================================
"""
A script to extract polynomial surrogate information (multiindex and coefficients)
and surrogate errors from a results.pk file generated by uq_pc.py
"""

## Import necessary libraries
import argparse
import sys
import numpy as np

if (sys.version_info.major==2):
    import cPickle as pick
elif (sys.version_info.major==3):
    import pickle as pick
else:
    print("Only Python 2 or 3 are supported. Exiting.")
    sys.exit()

## Parse arguments
usage_str = 'A script to extract polynomial surrogate information (multiindex and coefficients) \
and surrogate errors from a results.pk file generated by uq_pc.py. \
Creates mindex*.dat and pccf*.dat files and surr_errors.dat file.'

parser = argparse.ArgumentParser(description=usage_str,formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument("-p", "--pmtype",  dest="pmtype",  type=str,   default='pc',       help="Polynomial model type",  choices=['pc','pcs','pcx'])
parser.add_argument("-t", "--trval",   dest="trval",   type=str,   default='training', help="Error based on training or validation",  choices=['training', 'validation'])
parser.add_argument("-e", "--errtype", dest="errtype",  type=str,   default='misfit',  help="Surrogate error type",  choices=['misfit','bayes'])
args = parser.parse_args()

pmtype  = args.pmtype
trval   = args.trval
errtype = args.errtype

## Read the pickle file
pkfile='results.pk'
print("Unrolling surrogate results in file : " + pkfile)
results=pick.load(open(pkfile, 'rb'))

## Read polynomial coefficients/multiindices and write to a text file
if pmtype=='pcs':
    for iout in range(results['training'][2].shape[1]):
        pcf=results['pcmi'][0][iout]
        mindex=results['pcmi'][1][iout]
        np.savetxt("pccfp."+str(iout)+"_all.dat",pcf)
        np.savetxt("mindexp."+str(iout)+"_all.dat",mindex,fmt='%d')

else:
    pcf=results['pcmi'][0]
    mindex=results['pcmi'][1][0]
    if pmtype=='pc':
        np.savetxt('pccf_all_all.dat',np.array(pcf).T)
        np.savetxt('mindexp.dat',mindex,fmt='%d')
    elif pmtype=='pcx':
        np.savetxt('pccfpx.dat',np.array(pcf).T)
        np.savetxt('mindexpx.dat',mindex,fmt='%d')


## Read the y-values and extract error measure
ydata = results[trval][2]
ndata = ydata.shape[0]
nout  = ydata.shape[1]

## Extract error measure and scale appropriately
if errtype=='misfit':
    errval=results['err'][int(trval=='validation')] # use [0] for training and [1] for validation
    surr_err=np.empty((nout,))
    for i in range(nout):
        surr_err[i]=errval[i]*np.linalg.norm(ydata[:,i])/np.sqrt(ndata)
elif errtype=='bayes':
    errcheck_pc = results[trval][4]
    surr_err=np.sqrt(np.average(errcheck_pc**2,axis=0))
else:
    print("Error type is not recognized. Exiting.")
    sys.exit()

## Save in a file
np.savetxt('surr_errors.dat',surr_err)


## Extracted from uq_pc.py to help read results.pk
# if(args.num_val>0):
#     results = {'outs':(outrange),'training':(inqdp,inpar,ytrain,ytrain_pc,errcheck_pc),'validation':(qpar_val,inpar_val,yval,yval_pc,errcheck_val_pc),'pcmi':(pccf_all,mindex_all,varfrac_all,ccov_all,args.pc_type),'sens':(allsens_main,allsens_total,allsens_joint),'err':(err_training,err_val)}
# else:
#     results = {'outs':(outrange),'training':(inqdp,inpar,ytrain,ytrain_pc,errcheck_pc),'pcmi':(pccf_all,mindex_all,varfrac_all,ccov_all,args.pc_type),'sens':(allsens_main,allsens_total,allsens_joint),'err':(err_training,)}

