var express = require('express');
var router = express.Router();

var board = require('../controllers/board.ctrl');

/* GET home page. */
router.get('/toggleLED/:color', board.toggleLED);
router.get('/cycle/:amount', board.cycle);
router.get('/shutdown', board.shutdown)

module.exports = router;
