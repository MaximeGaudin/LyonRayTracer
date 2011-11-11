AC_INIT([lrt], [0.1], [gaudin.maxime@gmail.com])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CC
AC_PROG_CXX
AC_CONFIG_HEADERS([config.hh])
AC_CONFIG_FILES([Makefile])

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN"; then 
  AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([Doxyfile])])

AC_OUTPUT
