var app = angular.module('roomControl',['ngRoute']);

app.config(function ($routeProvider) {
    $routeProvider
        .when('/', {
            controller: 'indexCtrl',
            templateUrl: '/views/main.html'
        });
})