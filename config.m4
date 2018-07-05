dnl $Id$
dnl config.m4 for extension guanguans

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(guanguans, for guanguans support,
dnl Make sure that the comment is aligned:
[  --with-guanguans             Include guanguans support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(guanguans, whether to enable guanguans support,
dnl Make sure that the comment is aligned:
dnl [  --enable-guanguans           Enable guanguans support])

if test "$PHP_GUANGUANS" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, GUANGUANS_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-guanguans -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/guanguans.h"  # you most likely want to change this
  dnl if test -r $PHP_GUANGUANS/$SEARCH_FOR; then # path given as parameter
  dnl   GUANGUANS_DIR=$PHP_GUANGUANS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for guanguans files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GUANGUANS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GUANGUANS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the guanguans distribution])
  dnl fi

  dnl # --with-guanguans -> add include path
  dnl PHP_ADD_INCLUDE($GUANGUANS_DIR/include)

  dnl # --with-guanguans -> check for lib and symbol presence
  dnl LIBNAME=guanguans # you may want to change this
  dnl LIBSYMBOL=guanguans # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GUANGUANS_DIR/$PHP_LIBDIR, GUANGUANS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GUANGUANSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong guanguans lib version or lib not found])
  dnl ],[
  dnl   -L$GUANGUANS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GUANGUANS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(guanguans, guanguans.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
