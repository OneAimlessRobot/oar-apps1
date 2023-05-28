1/*	Narcissa

Aluno 1: 62411 Adriano Antonio Campos Valente <-- mandatory to fill
Aluno 2: ?number ?name <-- mandatory to fill

Comentario:

O ficheiro "Narcissa.js" tem de incluir, logo nas primeiras linhas,
um comentário inicial contendo: o nome e número dos dois alunos que
realizaram o projeto; indicação de quais as partes do trabalho que
foram feitas e das que não foram feitas (para facilitar uma correção
sem enganos); ainda possivelmente alertando para alguns aspetos da
implementação que possam ser menos óbvios para o avaliador.

0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
*/



// GLOBAL CONSTANTS

const ANIMATION_EVENTS_PER_SECOND = 4;

const IMAGE_NAME_EMPTY = "empty";
const IMAGE_NAME_INVALID = "invalid";
const IMAGE_NAME_SHRUB = "shrub";
const IMAGE_NAME_BERRY_BLUE = "berryBlue";
const IMAGE_NAME_SNAKE_HEAD = "snakeHead";
const IMAGE_NAME_SNAKE_MODULE = "snakeHead";


// GLOBAL VARIABLES

let control;	// Try not no define more global variables
let pause=0;
let time=0
// ACTORS

class Actor {
	constructor(x, y, imageName) {
		this.x = x;
		this.y = y;
		this.atime = 0;	// This has a very technical role in the control of the animations
		this.imageName = imageName;
		this.show();
	}
	draw(x, y, image) {
		control.ctx.drawImage(image, x * ACTOR_PIXELS_X, y * ACTOR_PIXELS_Y);
	}
	show() {
		this.checkPosition();
		control.world[this.x][this.y] = this;
		this.draw(this.x, this.y, GameImages[this.imageName]);
	}
	hide() {
		control.world[this.x][this.y] = control.getEmpty();
		this.draw(this.x, this.y, GameImages[IMAGE_NAME_EMPTY]);
	}
	move(dx, dy) {
		this.hide();
		this.x += dx;
		this.y += dy;
		this.show();
	}
	handleObjects(){
	}
	animation(x, y) {
	}
	checkPosition() {
			if(this.x>=70){
			
				this.x=1
			}
			if(this.x<=0){
			
				this.x=69
			}
			if(this.y>=40){
			
				this.y=1
			}
			if(this.y<=0){
			
				this.y=39
			}
		 
	}
}


class Shrub extends Actor {
	constructor(x, y, color) { 
	super(x, y, IMAGE_NAME_SHRUB); 
	this.components=[]
	
	
	}
	grow(){
	
	
	
	}
}

class Empty extends Actor {
	constructor() {
		super(-1, -1, IMAGE_NAME_EMPTY);
		this.atime = Number.MAX_SAFE_INTEGER;	// This has a very technical role
	}
	show() {}
	hide() {}
}

class Invalid extends Actor {
	constructor(x, y) { super(x, y, IMAGE_NAME_INVALID); }
}


class Berry extends Actor {
	constructor(x, y, color) {
		super(x, y, color);
	}
}


class SnakeModule extends Actor {
	constructor(x,y) {
		super(x,y, IMAGE_NAME_SNAKE_HEAD);
	}
}

class Snake extends Actor {
	constructor(x, y) {
		super(x, y, IMAGE_NAME_SNAKE_HEAD);
		[this.movex, this.movey] = [1,0];
		this.eatables=[IMAGE_NAME_BERRY_BLUE,IMAGE_NAME_SHRUB]
		this.objectsAround=[]
		this.lastPositions=[]
		this.trailLength=0
	}
	handleKey() {
		let k = control.getKey();
		if (k === null)	// ignore
			;
		else if (typeof(k) === "string"){	// special command
			// special command
			let i=0
			i=1
			}
			//mesg("special command == " + k)
		else {	// change direction
			let kx, ky;
			[this.movex, this.movey] = k;
			//mesg("change direction == " + k)
		}
	}
	getPos(){
	
		return [this.x,this.y]
	}
	setPos(newX,newY){
		[this.x,this.y]=[newX,newY]
		
	}
	handleObjects(){
		if(this.objectsAround.find(e => e.imageName === 'shrub')){
			this.die();
		}
		if(this.objectsAround.find(e => e.imageName === "berryBlue")){
			let k=0;
			for(;k<this.objectsAround.length;k++){
				let j=this.objectsAround[k]
				if(j.imageName==="berryBlue"){
				
					j.hide()
					this.eat();
				}	
				
			
			}
		}
	
	}
	renderTrail(){
		for(let i=0;i<this.trailLength;i++){
			control.world[this.lastPositions[i][0]][this.lastPositions[i][1]]=new SnakeModule(this.lastPositions[i][0],this.lastPositions[i][1])
			control.world[this.lastPositions[i][0]][this.lastPositions[i][1]].show()
		}
		
		
	
	}
	hideTrail(){
		for(let i=0;i<this.lastPositions.length;i++){
			control.world[this.lastPositions[i][0]][this.lastPositions[i][1]].hide()
		}
		
		
	
	}
	eat(){
		this.trailLength+=1
		}
	animation(x, y) {
		this.handleKey();
		if(this.lastPositions.length>0){
		this.hideTrail();
		}
		this.move(this.movex, this.movey);
		this.eyes()
		this.lastPositions.push([this.x-this.movex,this.y-this.movey])
		if(this.lastPositions.length>this.trailLength){
		this.lastPositions.shift();
		}
		if(this.lastPositions.length>0){
		this.renderTrail();
		}
	}
	eyes(){
		this.objectsAround=[
		control.world[this.x-1][this.y-1],//1
		control.world[this.x+1][this.y+1],//2
		control.world[this.x-1][this.y],//3
		control.world[this.x][this.y+1],//4
		control.world[this.x+1][this.y],//5
		control.world[this.x][this.y-1],//6
		control.world[this.x-1][this.y+1],//7
		control.world[this.x+1][this.y-1]//8
		]
		
		/*     168 	
		       3S5	
		       742	
		*/
		
		
	}
	die(){
	
		this.hide()
		this.hideTrail()
	}
}



// GAME CONTROL

class GameControl {
	constructor() {
		let c = document.getElementById('canvas1');
		control = this;	// setup global var
		this.key = 0;
		this.time = 0;
		this.ctx = document.getElementById("canvas1").getContext("2d");
		this.empty = new Empty();	// only one empty actor needed, global var
		this.world = this.createWorld();
		this.loadLevel(1);
		this.setupEvents();
	}
	getEmpty() {
		return this.empty;
	}
	createWorld() { // matrix needs to be stored by columns
		let world = new Array(WORLD_WIDTH);
		for( let x = 0 ; x < WORLD_WIDTH ; x++ ) {
			let a = new Array(WORLD_HEIGHT);
			for( let y = 0 ; y < WORLD_HEIGHT ; y++ )
				a[y] = this.empty;
			world[x] = a;
		}
		return world;
	}
	loadLevel(level) {
		if( level < 1 || level > MAPS.length )
			fatalError("Invalid level " + level)
		let map = MAPS[level-1];	// -1 because levels start at 1
		for(let x=0 ; x < WORLD_WIDTH ; x++)
			for(let y=0 ; y < WORLD_HEIGHT ; y++) {
					// x/y reversed because map is stored by lines
				GameFactory.actorFromCode(map[y][x], x, y);
			}
	}
	getKey() {
		let k = this.key;
		this.key = 0;
		switch( k ) {
			case 37: case 79: case 74: return [-1, 0];	// LEFT, O, J
			case 38: case 81: case 73: return [0, -1];	// UP, Q, I
			case 39: case 80: case 76: return [1, 0];	// RIGHT, P, L
			case 40: case 65: case 75: return [0,1];	// DOWN, A, K
			case 32: togglePause()
			case 0: return null;
			default: return String.fromCharCode(k);
		// http://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
		};	
	}
	setupEvents() {
		addEventListener("keydown", e => this.keyDownEvent(e), false);
		addEventListener("keyup", e => this.keyUpEvent(e), false);
		setInterval(() => this.animationEvent(), 1000 / ANIMATION_EVENTS_PER_SECOND);
	}
	animationEvent() {
		this.time++;
		time++;
		for(let x=0 ; x < WORLD_WIDTH ; x++)
			for(let y=0 ; y < WORLD_HEIGHT ; y++) {
				let a = this.world[x][y];
				if( a.atime < this.time ) {
					if(pause==0){
					a.atime = this.time;
					a.animation(x, y);
					a.handleObjects();
				}
				}
			}
	}
	keyDownEvent(e) {
		this.key = e.keyCode;
	}
	keyUpEvent(e) {
	}
}


// Functions called from the HTML page
function togglePause(){
	if(pause==1){
	
		pause=0
	}
	else{
	
		pause=1;
	}	
	
}
function onLoad() {
	// Asynchronously load the images an then run the game
	GameImages.loadAll(() => new GameControl());
}
function getTime(){

	return time;
}

function b1() { mesg("button1") }
function b2() { mesg("button2") }



