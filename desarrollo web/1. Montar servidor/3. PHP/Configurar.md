## Configuración de Apache

Tras instalar el servidor de Apache este aún no está preparado, por lo cual se deben seguir los siguientes pasos

1. Entrar al directorio de Apache `C:\Program Files\Apache\`

2. Editar el archivo de configuración como administrador  `conf\httpd.conf`

3. Cambiar la ubicación de la carpeta de donde tomara los archivos

~~~
#
# DocumentRoot: The directory out of which you will serve your
# documents. By default, all requests are taken from this directory, but
# symbolic links and aliases may be used to point to other locations.
#
DocumentRoot "C:/Program Files (x86)/Apache Software Foundation/Apache2.2/htdocs"
~~~

~~~
DocumentRoot "C:/Users/Usuario/Google Drive/www"
~~~

4. Cambiar la ubicación de la carpeta donde tomara los archivos

~~~
#
# Note that from this point forward you must specifically allow
# particular features to be enabled - so if something's not working as
# you might expect, make sure that you have specifically enabled it
# below.
#

#
# This should be changed to whatever you set DocumentRoot to.
#
<Directory "C:/Program Files (x86)/Apache Software Foundation/Apache2.2/htdocs">
    #
    # Possible values for the Options directive are "None", "All",
    # or any combination of:
    #   Indexes Includes FollowSymLinks SymLinksifOwnerMatch ExecCGI MultiViews
    #
    # Note that "MultiViews" must be named *explicitly* --- "Options All"
    # doesn't give it to you.
    #
    # The Options directive is both complicated and important.  Please see
    # http://httpd.apache.org/docs/2.2/mod/core.html#options
    # for more information.
    #
    Options Indexes FollowSymLinks

    #
    # AllowOverride controls what directives may be placed in .htaccess files.
    # It can be "All", "None", or any combination of the keywords:
    #   Options FileInfo AuthConfig Limit
    #
    AllowOverride None

    #
    # Controls who can get stuff from this server.
    #
    Order allow,deny
    Allow from all

</Directory>
~~~

~~~
<Directory "C:/Users/Usuario/Google Drive/www">
    Options FollowSymLinks -ExecCGI -Includes -Multiviews -Indexes
    AllowOverride All
    Order allow,deny
    #Deny from 127.0.0.1 host.example.com
    Allow from all
</Directory>
~~~

| Configuración | Descripción |
| --- | --- |
| Order | Controla el orden en que se evalúan las directivas Allow y Deny |
| AllowOverride | Cuando el valor de esta directiva es None, entonces los ficheros .htaccess son ignorados |

**Options**

| Configuración | Descripción |
| --- | --- |
| ExecCGI | Permite la ejecución de scripts CGI usando mod_cgi |
| FollowSymLinks | El servidor seguirá los enlaces simbólicos en este directorio sin revisar en el sistema de archivos, implica el uso de "Alias" y "RewriteEngine" |
| Includes | Permite el uso de Server-side usando mod_include. Permite agregar variables que serán remplazados por valores del servidor |
| Indexes | Devolverá una lista con los contenidos del directorio usando mod_autoindex |
| MultiViews | Devuelve contenido diferente de forma transparente usando mod_negotiation su uso se puede observar en el header "Content-Location:" |

5. Define el archivo índice del servidor

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
    AddType application/x-httpd-php .php5
    AddType application/x-httpd-php .php4
    AddType application/x-httpd-php-source .phps
</IfModule>
~~~

6. Evito el acceso al archivo de configuración `.htaccess`

~~~
#
# The following lines prevent .htaccess and .htpasswd files from being 
# viewed by Web clients. 
#
<FilesMatch "^\.ht">
    Order allow,deny
    Deny from all
    Satisfy All
</FilesMatch>
~~~

7. Por seguridad evitamos mostrar detalles del servidor como la versión

~~~
ServerSignature Off
ServerTokens Prod
~~~

8. Podemos elegir la codificación de caracteres

~~~
AddDefaultCharset on
AddDefaultCharset utf-8
#AddDefaultCharset ISO-8859-1
~~~

### Regla de firewall

~~~
NETSH advfirewall firewall add rule name="Apache Server 2.2" program="C:\Program Files (x86)\Apache Software Foundation\Apache2.2\bin\httpd.exe" protocol=TCP localport=80 dir=in action=allow enable=yes
~~~

## Referencias

* http://httpd.apache.org/docs/2.2/howto/ssi.html
* http://httpd.apache.org/docs/2.2/mod/core.html#options
* http://httpd.apache.org/docs/2.2/en/howto/access.html#host

## Autores

* [Angel González](https://github.com/mgrc45)

## Licencia

Este proyecto está licenciado bajo la licencia GNU General Public License v2.0.