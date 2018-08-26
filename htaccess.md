

#Como habilitar el archivo de configuracion ".htaccess" (Server Side Includes)

# Introducción

Apache® 2.x tiene mejores medidas de seguridad que las versiones anteriores, debido a que su configuración predeterminada viene de tal modo que deshabilita muchas cosas que podrán considerarse de cierto riesgo. Parte de esa seguridad incluye deshabilitar los SSI (Server Side Includes o Inclusiones del Lado del Servidor) y el uso de los archivos **.htaccess**. Estos últimos sirven para modificar o agregar funciones a directorios.

Básicamente solo se necesita agregar las siguientes líneas a cualquier definición del directorio que se desee utilizar:

```shell
Options Includes
AllowOverride All
```

## Fuentes

* http://www.alcancelibre.org/staticpages/index.php/18-como-apache-htaccess
* http://httpd.apache.org/docs/2.2/howto/ssi.html


#------------------------------------------------------------------------------
# Seguridad: Bloqueo acceso desde diversas IPs o Dominios
# http://httpd.apache.org/docs/2.2/en/howto/access.html#host
#------------------------------------------------------------------------------
Deny from 216.84.180.24 occ.com.mx
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# Personalizacion: Definimos nuestras paginas de error
# http://httpd.apache.org/docs/2.2/es/custom-error.html
#------------------------------------------------------------------------------
#ErrorDocument 500 "The server made a boo boo."
#ErrorDocument 404 /missing.html
#ErrorDocument 404 "/cgi-bin/missing_handler.pl"
#ErrorDocument 402 http://127.0.0.1/subscription_info.html
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# Seguridad: Evito que se acceda a ciertos archivos
# http://httpd.apache.org/docs/2.2/en/mod/core.html#filesmatch
#------------------------------------------------------------------------------
# Evito que se pueda acceder directamente a los 
# archivos que inicien con _ 
<FilesMatch "^\_(.+)$">
    Order allow,deny
    Deny from all
    Satisfy All
</FilesMatch>
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# Personalizacion: Redirijo las paginas
# http://httpd.apache.org/docs/2.2/en/howto/access.html#rewrite
# http://httpd.apache.org/docs/2.4/rewrite/intro.html#regex
#------------------------------------------------------------------------------
# Simbolos:
#	^: Señala el inicio del patron.
#	$: Señala que se termino de escribir un patron.
#	([A-Z]): Señala que solo acepta un caracter en mayuscula.
#	([A-Z]+): Señala que acepta varios caracteres mayusculas.
#	([0-9]+): Señala que acepta varios caracteres numericos.
#	(.+): Señala que acepta varios tipos de caracteres.
#	(.*): Señala que acepta varios tipos de caracteres.
#	[R]: Redirecciona "302 Found"
#	[R=permanent,L]: Redirecciona "301 Moved Permanently"
#	no a las direcciones de salida
# Mas info: RewriteRule Pattern Substitution
# http://httpd.apache.org/docs/2.0/misc/rewriteguide.html
# http://httpd.apache.org/docs/1.3/mod/mod_rewrite.html
# http://www.widexl.com/tutorials/mod_rewrite.html#rewriterule
#------------------------------------------------------------------------------
<IfModule rewrite_module>
 Options +FollowSymLinks
 RewriteEngine On
 RewriteCond %{HTTP_HOST} ^(localhost|127.0.0.1)$
 #http://localhost/empleos
 # RewriteRule ^empleos$ /empleos/ [R=permanent]
 #http://localhost/empleos/
 # RewriteRule ^empleos/$ /empleos/navi.php [L]
 #http://localhost/empleos/533
 # RewriteRule ^empleos/([0-9]+)$ /empleos/offer.php?id=$1 [L]
 #http://localhost/empleos/Distrito-Federal
 # RewriteRule ^empleos/([A-Za-z-]+)$ /empleos/$1/ [R=permanent]
 #http://localhost/empleos/Distrito-Federal/
 # RewriteRule ^empleos/([A-Za-z-]+)/$ /empleos/navi.php?stateStr=$1 [L]
 #http://localhost/empleos/Distrito-Federal/533
 # RewriteRule ^empleos/([A-Za-z-]+)/([0-9]+)$ /empleos/offer.php?stateStr=$1&id=$2 [L]
 #http://localhost/empleos/Distrito-Federal/Iztacalco
 # RewriteRule ^empleos/([A-Za-z-]+)/([A-Za-z-]+)$ /empleos/$1/$2/ [R=permanent]
 #http://localhost/empleos/Distrito-Federal/Iztacalco/
 # RewriteRule ^empleos/([A-Za-z-]+)/([A-Za-z-]+)/$ /empleos/navi.php?stateStr=$1&cityStr=$2 [L]
 #http://localhost/empleos/Distrito-Federal/Iztacalco/533
 # RewriteRule ^empleos/([A-Za-z-]+)/([A-Za-z-]+)/([0-9]+)$ /empleos/offer.php?stateStr=$1&cityStr=$2&id=$3 [L]
 #http://localhost/email/imagenes/001/banner01.jpg
 # RewriteRule ^email/imagenes/([0-9]+)/(.+)$ /email/imagenes.php?id=$1&name=$2 [L] 
</IfModule>
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# Funcion: Defino la hoja de caracteres predeterminada
#------------------------------------------------------------------------------
AddDefaultCharset on
AddDefaultCharset utf-8
#AddDefaultCharset ISO-8859-1
#------------------------------------------------------------------------------


<IfModule mod_php5.c>
#------------------------------------------------------------------------------
# Funcion(PHP): Deshabilita el uso de variables globales
#------------------------------------------------------------------------------
php_flag register_globals Off
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Funcion(PHP): Habilita la compresion gzip
#------------------------------------------------------------------------------
php_flag zlib.output_compression on
php_value zlib.output_compression_level 9
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Funcion(PHP): Tamaño maximo del archivo
#------------------------------------------------------------------------------
php_value upload_max_filesize 8M
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Funcion(PHP): Magic Quotes
#------------------------------------------------------------------------------
# ' (comilla-simple), " (comilla doble), \ (diagonal) y caracteres "NULL"
# todos son escapados con una diagonal. Es equivalente a usar "addslashes()"
#------------------------------------------------------------------------------
php_flag magic_quotes_gpc Off
php_flag magic_quotes_runtime Off
#php_admin_flag magic_quotes_sybase = Off
#------------------------------------------------------------------------------
</IfModule>
