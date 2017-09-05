var express = require('express');
var router = express.Router();

var indexCtrl = require('../controllers/index.ctrl');

/* GET home page. */
router.get('/', indexCtrl.main);

module.exports = router;
