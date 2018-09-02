## Instalación de PHP 7 en Windows 10

Tras instalar el sevidor de apache 2.4.x podemos instalar el interprete de PHP el cual fue compilado para windows y dependiendo de la version necesitaremos un componente de Visual Studio.

Debemos elegir es la versión **Thread Safe**, ya que es la que va con Apache, la **Non-Thread Safe** está mejorada para utilizar con Windows e IIS, pero no con Apache, por eso la elección.

La mayoria de servidores en internet usan Apache sobre linux combinacion tambien conocida como LAMP (Linux Apache MySQL Php) si bien vamos a usar un PC con Windows para desarrollar es deseable que nuestras aplicaciones corran lo más parecido posible para evitar problemas de compatibilidad al montarlo en un servidor de terceros.

**Descargar**
* VC15: [Visual C++ Redistributable for Visual Studio 2017](https://aka.ms/vs/15/release/VC_redist.x64.exe)
* Paquete de PHP 7 compilado para windows [php-7.2.7-Win32-VC15-x64.zip](https://windows.php.net/downloads/releases/archives/php-7.2.7-Win32-VC15-x64.zip)

**Instalar**

1. Creamos el directorio de PHP en windows `C:\Program Files\PHP\`

2. Descomprimimos el paquete `php-7.2.7-Win32-VC15-x64` en el directorio recien creado

3. Renombramos `php.ini-development` por `php.ini`

4. Agregamos la siguiente linea en el archivo `C:\Program Files (x86)\Apache Software Foundation\Apache2.2\conf\httpd.conf`

~~~
#BEGIN PHP INSTALLER EDITS - REMOVE ONLY ON UNINSTALL
PHPIniDir "C:/Program Files/PHP"
LoadModule php7_module "C:/Program Files/PHP/php7apache2_4.dll"
#END PHP INSTALLER EDITS - REMOVE ONLY ON UNINSTALL
~~~

5. Remplazamos la siguiente linea

~~~
#
# DirectoryIndex: sets the file that Apache will serve if a directory
# is requested.
#
<IfModule dir_module>
    DirectoryIndex index.html
</IfModule>
~~~

~~~
<IfModule dir_module>
    DirectoryIndex index.php index.html
    AddType application/x-httpd-php .php
    AddType application/x-httpd-php-source .phps
</IfModule>
~~~

**Referencias**

* https://windows.php.net/downloads/releases/archives/

## Autores

* [Angel González](https://github.com/mgrc45)

## Licencia

Este proyecto está licenciado bajo la licencia GNU General Public License v2.0.
