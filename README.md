开发一个简单的 PHP 扩展来学习 PHP 扩展开发和 PHP 内核

## 安装

### 下载

``` bash
git clone https://github.com/guanguans/guanguans-php-ext.git
```
### 编译安装

``` bash
/path/to/phpize
./configure --with-php-config=/path/to/php-config
make -j && make install
```

### php.ini 中添加

``` bash
extension = guanguans.so
```

### 重启 php-fpm

``` bash
systemctl restart php-fpm.service
```

## 使用

### 查看拓展

![](./docs/guanguans-1.png)

![](./docs/guanguans-2.png)

### 测试

![](./docs/guanguans-3.png)

![](./docs/guanguans-4.png)

## License

[Apache License 2.0](./LICENSE)
