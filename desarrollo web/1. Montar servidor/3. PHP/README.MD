## Instalación de PHP 7 en Windows 10

Tras instalar el sevidor de apache 2.4.x podemos instalar el interprete de PHP el cual fue compilado para windows y dependiendo de la version necesitaremos un componente de Visual Studio.

> Las versiones **Thread Safe** son paquetes compilados para ser mas estables debido a su uso de multi-tareas teniendo repercusiones negativas en el desempeño

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
