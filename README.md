# 开发一个简单的 PHP 扩展来学习 PHP 扩展开发和 PHP 内核

## 一、安装扩展

1.1 git clone

git clone https://github.com/guanguans/guanguans-php-ext.git

1.2 编译安装拓展

``` sh
$ /path/to/phpize
$ ./configure --with-php-config=/path/to/php-config
$ make -j && make install
```

1.3、在 php.ini 最后添加

``` sh
extension = guanguans.so
```

1.4 重启 php-fpm

## 二、使用扩展

1. 查看已经安装的拓展


2. 测试一下拓展

