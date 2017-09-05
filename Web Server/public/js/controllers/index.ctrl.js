app.controller("indexCtrl", function ($scope, $http) {

    $scope.runCycles = function () {
        if ($scope.cycleNumOfTimes > 0) {
            $http.get("/board/cycle/" + $scope.cycleNumOfTimes).then(function () {

            });

        }
    }

    $scope.lights = [];
    for(let i=0; i<6; i++){
        $scope.lights.push(true);
    }

    $scope.toggleLight = function(lightId){
        $http.get('/board/toggleLED/'+lightId).then(function () {
            $scope.lights[lightId] = !$scope.lights[lightId];
        });
    }
    
    $scope.shutdownAll = function () {
        $http.get('/board/shutdown').then(function () {
            for(let i=0; i<6; i++){
                $scope.lights[i] = true;
            }

        });
    }


});


