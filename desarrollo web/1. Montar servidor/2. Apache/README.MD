## Instalación de Apache en Windows 10

Apache es uno de los servidores web más utilizados a nivel mundial por su estabilidad y desempeño. Es nativo en la mayoría de distribuciones linux y da origen a diferentes proyectos como **ApacheHaus**, **Apache Lounge**, **BitNami WAMP Stack**, **WampServer**, **XAMPP** entre otros.

La ultima version del proyecto se puede descargar desde la pagina [apache.org](http://httpd.apache.org/download.cgi) sin embargo dentro de las [versiones archivadas](http://archive.apache.org/dist/httpd/binaries/win32/) el ultimo binario compilado para windows [httpd-2.2.25-win32-x86-openssl-0.9.8y.msi](http://archive.apache.org/dist/httpd/binaries/win32/httpd-2.2.25-win32-x86-openssl-0.9.8y.msi) corresponde a la version 2.2.25 que si bien ofrece un paquete de instalacion MSI. Es una version compilada en el 2013 y no es conveniente por cuestiones de seguridad.

Motivo por el cual usaremos una version compilada de terceros [apachelounge.com](http://www.apachelounge.com/download/) esta version requiere instalar un componente de Visual Studio para tener las librerias de C++ disponibles, ademas de una instalacion manual. Sin embargo es una version mas reciente 2.4.34 compilada para sistemas de 64 bits y con las ultimas actualizaciones de seguridad.

## Descargar

* VC15: [Visual C++ Redistributable for Visual Studio 2017](https://go.microsoft.com/fwlink/?LinkId=746572)
* Paquete de Apache 2.4 compilado para windows [httpd-2.4.34-win64-VC15.zip](http://home.apache.org/~steffenal/VC15/binaries/httpd-2.4.34-win64-VC15.zip)

## Instalar

1. Creamos el directorio de Apache en windows `C:\Program Files\Apache\`

2. Descomprimimos el contenido de `httpd-2.4.34-win64-VC15.zip\Apache24\` en el directorio recien creado

3. Cambiar la ruta del servidor dentro del archivo de configuracion `C:\Program Files\Apache\conf\httpd.conf`

~~~
Define SRVROOT "C:/Program Files/Apache"
~~~

4. Ejecutar la consola `cmd` como administrador

5. Entrar al directorio de Apache `C:\Program Files\Apache\`

6. Instalar apache como servicio de windows, para desinstalar puede usar `bin\httpd.exe -k uninstall`

~~~
bin\httpd.exe -k install -n "Apache Server"
~~~

> **Nota:** De forma automatica el instalador crea una excepcion para el firewall permitiendo el `puerto 80` para nuestro servidor `httpd.exe`

**Referencias**
* http://httpd.apache.org/docs/2.4/platform/windows.html

## Autores

* [Angel González](https://github.com/mgrc45)

## Licencia

Este proyecto está licenciado bajo la licencia GNU General Public License v2.0.
