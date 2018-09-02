## Instalación de PHP 7 en Windows 10

Apache es uno de los servidores web más utilizados por su estabilidad y desempeño. Es nativo en la mayoría de distribuciones de linux y de él se basan diferentes proyectos como **ApacheHaus**, **Apache Lounge**, **BitNami WAMP Stack**, **WampServer**, **XAMPP** entre otros.

PHP 7 requiere el componente de Visual C++ Redistributable for Visual Studio 2017 [VC15](https://aka.ms/vs/15/release/VC_redist.x64.exe) para poder ejecutar el paquete [php-7.2.7-Win32-VC15-x64.zip](https://windows.php.net/downloads/releases/archives/php-7.2.7-Win32-VC15-x64.zip).

> Las versiones **Thread Safe** son paquetes compilados para ser mas estables debido a su uso de multi-tareas teniendo repercusiones negativas en el desempeño

1. Creamos el directorio de PHP en windows `C:\Program Files\PHP\`

2. Descomprimimos el paquete `php-7.2.7-Win32-VC15-x64` en el directorio recien creado

3. Renombramos `php.ini-development` por `php.ini`

4. Agregamos la siguiente linea en el archivo `C:\Program Files (x86)\Apache Software Foundation\Apache2.2\conf\httpd.conf`

~~~
#BEGIN PHP INSTALLER EDITS - REMOVE ONLY ON UNINSTALL
PHPIniDir "C:/Program Files/PHP"
LoadModule php7_module “C:/Program Files/PHP/php7apache2_4.dll”
#END PHP INSTALLER EDITS - REMOVE ONLY ON UNINSTALL
~~~

**Referencias**

* https://windows.php.net/downloads/releases/archives/

## Autores

* [Angel González](https://github.com/mgrc45)

## Licencia

Este proyecto está licenciado bajo la licencia GNU General Public License v2.0.
