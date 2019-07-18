const xtk = require('xtk');
var renderer = new xtk.Renderer('Simba');
var vertices = [
    new xtk.Vector3(1, 3, 1),
    new xtk.Vector3(1, 3, -1),
    new xtk.Vector3(1, -1, 1),
    new xtk.Vector3(1, -1, -1),
    new xtk.Vector3(-1, 3, -1),
    new xtk.Vector3(-1, 3, 1),
    new xtk.Vector3(-1, -1, -1),
    new xtk.Vector3(-1, -1, 1)
];

var faces = [
    new xtk.Face3(0, 2, 1),
    new xtk.Face3(2, 3, 1),
    new xtk.Face3(4, 6, 5),
    new xtk.Face3(6, 7, 5),
    new xtk.Face3(4, 5, 1),
    new xtk.Face3(5, 0, 1),
    new xtk.Face3(7, 6, 2),
    new xtk.Face3(6, 3, 2),
    new xtk.Face3(5, 7, 0),
    new xtk.Face3(7, 2, 0),
    new xtk.Face3(1, 3, 4),
    new xtk.Face3(3, 6, 4)
];

renderer.setClearColor('#335c5c');
renderer.setSize(800, 600);
renderer.render();