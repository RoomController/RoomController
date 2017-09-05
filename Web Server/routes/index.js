var express = require('express');
var router = express.Router();

var index = require('../controllers/index.ctrl');

/* GET home page. */
router.get('/', index.main);

module.exports = router;
