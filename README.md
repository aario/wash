# W.A.S.H
## Web Application / Shell Gateway

The simplest and easiest way to make UI applications using console scripting languages.

simply run `wash` inside the folder of your web application and from your shell/python/etc script. 
Your web application will run inside a QtWebEngine / Webkit based browser.
Whatever your javascript sends to the function:
```
    channel.echo("Hello World")
```
Will be sent to stdout as:
```
JS>Hello World
```
And whatever you send to the stdin of `wash`, will be executed on your web application:
```
    wash < echo "Hello World"
```
Example web application and shell script provided inside example folder.
