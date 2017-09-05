var app = angular.module('roomControl',['ngRoute']);

app.config(function ($routeProvider) {
    $routeProvider
        .when('/', {
            controller: 'indexCtrl',
            templateUrl: '/views/main.html'
        })
        .when('/control', {
            controller: 'indexCtrl',
            templateUrl: '/views/main.html'
        })
        .when('/team', {
            controller: 'indexCtrl',
            templateUrl: '/views/team.html'
        })
        .when('/setup', {
            controller: 'indexCtrl',
            templateUrl: '/views/setup.html'
        })
        .otherwise({
            redirect: '/'
        });
})