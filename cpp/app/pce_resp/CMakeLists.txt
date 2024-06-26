project (UQTk)

add_executable (pce_resp pce_resp.cpp)

target_link_libraries (pce_resp uqtkpce  )
target_link_libraries (pce_resp uqtkquad )
target_link_libraries (pce_resp uqtktools)
target_link_libraries (pce_resp uqtkarray)

target_link_libraries (pce_resp depdsfmt )
target_link_libraries (pce_resp sundials_cvode)
target_link_libraries (pce_resp sundials_nvecserial)
target_link_libraries (pce_resp sundials_sunlinsoldense)
target_link_libraries (pce_resp sundials_sunmatrixdense)
target_link_libraries (pce_resp depslatec)
target_link_libraries (pce_resp depfigtree )
target_link_libraries (pce_resp depann   )


# Link fortran libraries
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  if ("${GnuLibPath}" STREQUAL "")
    target_link_libraries (pce_resp gfortran stdc++)
  else()
    target_link_libraries (pce_resp ${GnuLibPath}/libgfortran.a ${GnuLibPath}/libquadmath.a stdc++)
  endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel
  if ("${IntelLibPath}" STREQUAL "")
    target_link_libraries (pce_resp ifcore)
  else()
    target_link_libraries (pce_resp ${IntelLibPath}/libifcore.a)
  endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using Clang
  if ("${ClangLibPath}" STREQUAL "")
    target_link_libraries (pce_resp gfortran stdc++)
  else()
    target_link_libraries (pce_resp ${ClangLibPath}/libgfortran.dylib ${ClangLibPath}/libquadmath.dylib ${ClangLibPath}/libstdc++.dylib)
  endif()
endif()

target_link_libraries (pce_resp m lapack ${LAPACK_LIBRARIES})
target_link_libraries (pce_resp m blas ${BLAS_LIBRARIES})

include_directories(../../lib/pce    )
include_directories(../../lib/array  )
include_directories(../../lib/include)
include_directories(../../lib/quad   )
include_directories(../../lib/tools  )

include_directories(../../../dep/dsfmt)
include_directories(../../../dep/figtree)
include_directories (${CMAKE_SUNDIALS_DIR}/include)
if( BUILD_SUNDIALS)
  include_directories (../../../dep/sundials/include )
  include_directories ("${PROJECT_BINARY_DIR}/../../../dep/sundials/include")
endif()
INSTALL(TARGETS pce_resp DESTINATION bin)
