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
const IMAGE_NAME_BERRY_BROWN = "berryBrown"; 
const IMAGE_NAME_BERRY_CYAN = "berryCyan"; 
const IMAGE_NAME_BERRY_DGREEN = "berryDarkGreen"; 
const IMAGE_NAME_BERRY_GREEN = "berryGreen"; 
const IMAGE_NAME_BERRY_ORANGE = "berryOrange"; 
const IMAGE_NAME_BERRY_PURPLE = "berryPurple"; 
const IMAGE_NAME_SNAKE_HEAD = "snakeHead";
const IMAGE_NAME_SNAKE_MODULE = "snakeHead";


// GLOBAL VARIABLES

let control;	// Try not no define more global variables
let pause=true;
let gameOver=false
// ACTORS

class Actor {
	constructor(x, y, imageName) {
		this.x = x;
		this.y = y;
		this.atime = 0;	// This has a very technical role in the control of the animations
		this.imageName = imageName;
		this.neighbourPositions=[]
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
	handleBehaviour(){
	}
	eyes(){
		this.neighbourPositions=[
		[this.x-1,this.y-1],//1
		[this.x+1,this.y+1],//2
		[this.x-1,this.y],//3
		[this.x,this.y+1],//4
		[this.x+1,this.y],//5
		[this.x,this.y-1],//6
		[this.x-1,this.y+1],//7
		[this.x+1,this.y-1]//8
		]
		
		/*     168 	
		       3S5	
		       742	
		*/
		
		
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
	this.nextGrowtime=this.getNextGrowTimeInc()
	
	
	}
	getNextGrowTimeInc(){
	
		return 4*(3+rand(4));
	
		}
	
	getNextGrowTime(){		
	
	this.nextGrowtime=this.nextGrowtime+this.getNextGrowTimeInc();
	}
	growInSize(){
		let slot=rand(this.neighbourPositions.length);
		let pos=this.neighbourPositions[slot]
		//Escolhe nova posiçao caso a que calhou seja invalida.
		//Fazer este loop ate calhar uma que funcione
		if(pos[0]>=70||pos[0]<0||pos[1]<0||pos[1]>=40
					||
		control.world[pos[0]][pos[1]].imageName==="shrub"){
		
		slot=rand(this.neighbourPositions.length);
			pos=this.neighbourPositions[slot]
		}
		control.world[pos[0]][pos[1]]=new Shrub(pos[0],pos[1]);
	
	
	}
	animation(x,y){
	
		this.handleBehaviour();
	
	}
	handleBehaviour(){
		this.eyes()
		if(control.time== this.nextGrowtime){
		
			this.growInSize();
			this.getNextGrowTime();
			
		}
	
		
		
	
	
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
		switch(color){
		case "berryBlue": this.score=1;
		case "berryBrown": this.score=2;
		case "berryCyan": this.score=3;
		case "berryDarkGreen": this.score=4;
		case "berryGreen": this.score=5;
		case "berryOrange": this.score=6;
		case "berryPurple": this.score=7;
		
		
		
		}
	}
	getColor(){
	
		return this.imageName;
	}
	getScore(){
		
		return this.score;
	}
	
}

class EatenBerry extends Berry{

	constructor(x,y,color){
	
		super(x,y,color);
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
		this.startSize=4;
		this.maxStomachSize=5;
		this.dead=false;
		[this.movex, this.movey] = [1,0];
		this.body=[]
		this.stomach=[]
		
		for(let i=0;i<this.startSize;i++){
			
			this.body.push(
		[this.x-i,this.y]);
		
		}
		this.trailSize=this.startSize
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
	filterUsefulNeigbhours()
	{
	
		let size=this.neighbourPositions.length;
		for(let i=0;i<size;i++){
			let pos=this.neighbourPositions[i]
			if(control.world[pos[0]]===undefined){
				
				this.neighbourPositions.splice(i,1);
				break;
			
			
			}
			if(control.world[pos[0]][pos[1]]===undefined){
				
				this.neighbourPositions.splice(i,1);
				break;
			
			
			}
		}
	
		
	
	
	}
	handleBehaviour(){
		
		this.eyes()
		let size=this.neighbourPositions.length;
		this.filterUsefulNeigbhours();
		for(let i=0;i<size;i++){
		
			let pos=this.neighbourPositions[i]
			if(control.world[pos[0]][pos[1]].imageName==="shrub"){
				
				this.die();
				break;
			
			
			}
			if(control.world[pos[0]][pos[1]].constructor.name === Berry.name){
				let berry=control.world[pos[0]][pos[1]];
				berry.hide()
				this.eat(berry);
				break;
			
		}
		}
		}
		
	renderTrail(){
		console.log("corpo: "+this.body+" estomago: "+this.stomach)
		if(this.body.length>0){
		
		for(let i=0;i<this.stomach.length;i++){
			let pos=this.body[i]
		if(!(pos[0]>=70||pos[0]<0||pos[1]<0||pos[1]>=40)){
			control.world[pos[0]][pos[1]]=new	EatenBerry(pos[0],pos[1],this.stomach[i])
		}
		}
		for(let i=this.stomach.length;i<this.body.length;i++){
		let pos=this.body[i]
		if(!(pos[0]>=70||pos[0]<0||pos[1]<0||pos[1]>=40)){
			control.world[pos[0]][pos[1]]=new	SnakeModule(pos[0],pos[1])
		}
			
		}
	}
	}
	hideTrail(){
		if(this.body.length>0){
		for(let i=0;i<this.body.length;i++){
			let pos=this.body[i]
		//if manhoso para permitir deslocaçoes pseudoesfericas com
		//cauda nao vazia
		if(!(pos[0]>=70||pos[0]<0||pos[1]<0||pos[1]>=40)){ 
			control.world[pos[0]][pos[1]].hide()
		}
		}
		}
	}
	updateTrail(){
	
		this.body.push(
		[this.x,this.y]
		)
		if(this.body.length>this.trailSize){
		this.body.shift()
		}
	
	
	}
	eat(berry){
		//for(let i=0;i<berry.getScore();i++){
		this.trailSize+=1
		this.body.push(
		[this.x-this.movex,this.y-this.movey]
		)
		//}
		this.stomach.push(
		[berry.getColor()]
		)
		if(this.stomach.length>this.maxStomachSize){
		this.stomach.shift();
		}
	}
	animation(x, y) {
		this.handleKey();
		this.hideTrail();
		this.eyes()
		this.updateTrail();
		this.move(this.movex, this.movey);
		this.handleBehaviour()
		this.renderTrail()
	}
	die(){
		gameOver=true;
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
	if(!pause&&!gameOver){
		getTime(this.time);
		this.time++;
		for(let x=0 ; x < WORLD_WIDTH ; x++)
			for(let y=0 ; y < WORLD_HEIGHT ; y++) {
				let a = this.world[x][y];
				if( a.atime < this.time ) {
					a.atime = this.time;
					a.animation(x, y);
				}
			}
		}
	else if(gameOver){
	
		document.getElementById("timer").innerHTML= "Acabou"
	
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
	if(pause==true){
	
		pause=false
	}
	else{
	
		pause=true;
	}	
	
}
function start(){

	let startButton=document.getElementById("startButton")
	startButton.style.display="none";
	onLoad();
	togglePause();
	let pauseButton=document.getElementById("pauseButton");
	 pauseButton.style.display = "block";
}
function onLoad() {
	// Asynchronously load the images an then run the game
	GameImages.loadAll(() => new GameControl());
}
function getTime(timeValue){

	let timer=document.getElementById("pauseButton");
	timer.innerHTML="The time: "+ timeValue
}

function b1() { mesg("button1") }
function b2() { mesg("button2") }



