var express = require('express');
var http = require('http');														// use the http lib for nodejs
var url = require('url');														// url-module is used to parse and manipulate url's

var app = express();

//app.set('port', 8080);

var server = http.createServer(function(request, response){						// Here we pass an anonymous function, that decide what to do on connection
	console.log('Connection');													// On every connect/response interaction with our server, write 'Connection' in cmd line
	var path = url.parse(request.url).pathname;									// Here we add other paths, than root ex. localhost:8001/some_other_path

	switch(path){																// decide what the server should do, depending on which path we use.
		case'/':
			response.writeHead(200, {'Content-Type': 'text/html'});				// Here we define what data-type to use, when writing our response header
			response.write('Hello World');										// Here we write the actual response to the header, more precisely our html message
			response.end();
			break;
		case '/blink':
			response.writeHead(200, {'Content-Type': 'text/html'});
			response.write('1');
			console.log('Connected to Blink');
			response.end();
			break;
		default:
			response.writeHead(404);
			response.write("Oops, this doesn't exist - 404");					// Here we write the actual response to the header, more precisely our html message
			response.end();														// Here we end the response and action, and its also here we execute the response!
			break;
	}

});

//server.listen(8080);

var server_port = process.env.OPENSHIFT_NODEJS_PORT || 8080
var server_ip_address = process.env.OPENSHIFT_NODEJS_IP || '127.0.0.1'

server.listen(server_port, server_ip_address, function () {
  console.log( "Listening on " + server_ip_address + ", server_port " + server_port )
});
