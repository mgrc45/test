## Instalación de Apache en Windows 10

Apache es uno de los servidores web más utilizados por su estabilidad y desempeño. Es nativo en la mayoría de distribuciones de linux y de él se basan diferentes proyectos como **ApacheHaus**, **Apache Lounge**, **BitNami WAMP Stack**, **WampServer**, **XAMPP** entre otros.

## Descargar

* VC15: [Visual C++ Redistributable for Visual Studio 2017](https://go.microsoft.com/fwlink/?LinkId=746572)
* Paquete de Apache 2.4 compilado para windows [httpd-2.4.34-win64-VC15.zip](http://home.apache.org/~steffenal/VC15/binaries/httpd-2.4.34-win64-VC15.zip)

## Instalar

1. Creamos el directorio de Apache en windows `C:\Program Files\Apache\`

2. Descomprimimos el contenido del paquete `httpd-2.4.34-win64-VC15` en el directorio recien creado

3. Cambiar la ruta del servidor dentro del archivo de configuracion `C:\Program Files\Apache\conf\httpd.conf`

~~~
Define SRVROOT "C:/Program Files/Apache"
~~~

4. Ejecutar la consola `cmd` como administrador

5. Entrar al directorio de Apache `C:\Program Files\Apache\`

6. Instalar apache como servicio de windows, desinstalar puede eliminar el servicio usando `bin\httpd.exe -k uninstall`

~~~
bin\httpd.exe -k install -n "Apache Server"
~~~

> **Nota:** De forma automatica el instalador crea una excepcion para el firewall permitiendo el ´puerto 80´ para nuestro servidor `httpd.exe`

**Referencias**
* http://www.apachelounge.com/download/
* http://httpd.apache.org/download.cgi
* http://archive.apache.org/dist/httpd/binaries/win32/
* http://httpd.apache.org/docs/2.2/platform/windows.html
* https://httpd.apache.org/docs/current/platform/windows.html

## Autores

* [Angel González](https://github.com/mgrc45)

## Licencia

Este proyecto está licenciado bajo la licencia GNU General Public License v2.0.
