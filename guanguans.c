/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_guanguans.h"

/* If you declare any globals in php_guanguans.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(guanguans)
*/

/* True global resources - no need for thread safety here */
static int le_guanguans;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("guanguans.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_guanguans_globals, guanguans_globals)
    STD_PHP_INI_ENTRY("guanguans.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_guanguans_globals, guanguans_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string guanguans(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(guanguans)
{
	zend_string *strg;
	strg = strpprintf(0, "Hello, 琯琯, this is your first PHP extension. ");

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_guanguans_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_guanguans_init_globals(zend_guanguans_globals *guanguans_globals)
{
	guanguans_globals->global_value = 0;
	guanguans_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(guanguans)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(guanguans)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(guanguans)
{
#if defined(COMPILE_DL_GUANGUANS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(guanguans)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(guanguans)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "guanguans support", "enabled");
	php_info_print_table_row(2, "Version", PHP_GUANGUANS_VERSION);
    php_info_print_table_row(2, "Author", "琯琯[email: yzmguanguan@gmail.com]");
    php_info_print_table_row(2, "Functions", "guanguans()");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ guanguans_functions[]
 *
 * Every user visible function must have an entry in guanguans_functions[].
 */
const zend_function_entry guanguans_functions[] = {
	PHP_FE(guanguans,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in guanguans_functions[] */
};
/* }}} */

/* {{{ guanguans_module_entry
 */
zend_module_entry guanguans_module_entry = {
	STANDARD_MODULE_HEADER,
	"guanguans",
	guanguans_functions,
	PHP_MINIT(guanguans),
	PHP_MSHUTDOWN(guanguans),
	PHP_RINIT(guanguans),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(guanguans),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(guanguans),
	PHP_GUANGUANS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GUANGUANS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(guanguans)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
