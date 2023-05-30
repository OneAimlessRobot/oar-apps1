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
const IMAGE_NAME_BERRY_RED = "berryRed"; 
const IMAGE_NAME_SNAKE_HEAD = "snakeHead";

const goodBerryColours=["berryBlue",
			"berryCyan",
			"berryGreen",
			"berryDarkGreen",
			"berryOrange",
			"berryPurple",
			"berryRed"]
			
			
const GAME_ENDING_SCORE= 1000;
// GLOBAL VARIABLES

let control;	// Try not no define more global variables

// ACTORS

class Actor {
	constructor(x, y, imageName) {
		this.x = x;
		this.y = y;
		this.checkPosition();
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
	getPositionsAround(){
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
	checkPositionVar(xPos,yPos) {
			if(xPos>=70){
			
				return [1,yPos]
			}
			if(xPos<=0){
			
				return [69,yPos]
			}
			if(yPos>=40){
			
				return [xPos,1]
			}
			if(yPos<=0){
			
				return [xPos,39]
			}
			return [xPos,yPos]
		 
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

class DeadlyEntity extends Actor{

	constructor(x, y, image) { 
	super(x, y, image);
	
	
	}




}

class Shrub extends DeadlyEntity {
	constructor(x, y, color) { 
	super(x, y, IMAGE_NAME_SHRUB); 
	this.components=[]
	this.nextGrowtime=this.getNextGrowTimeInc()
	
	
	}
	getNextGrowTimeInc(){
	
		return 20+rand(80);
		}
	
	getNextGrowTime(){		
	
	this.nextGrowtime+=this.getNextGrowTimeInc();
	}
	growInSize(){
		let x=this.neighbourPositions.length;
		let arr=this.neighbourPositions;
		for(let i=0;i<x;i++){
			let betterPos=this.checkPositionVar(arr[i][0],arr[i][1])			
			let object=control.world[betterPos[0]][betterPos[1]];
			
			if(!(object instanceof Shrub)){
			
			object=new Shrub(betterPos[0],betterPos[1])
				
			
			}
		}
	
	
	}
	animation(x,y){
		this.hide()
		this.handleBehaviour();
		this.show()
	
	}
	handleBehaviour(){
		this.getPositionsAround()
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

class Edible extends Actor{
constructor(x, y, image) { 
	super(x, y, image);
	
	
	}

}
class Berry extends Edible {
	constructor(x, y, color) {
		super(x, y, color);
		this.afloat=true;
		this.deadLine=control.time+20+rand(80)
		this.score=1;
	}
	getColor(){
	
		return this.imageName;
	}
	animation(x,y){
	if(this.afloat){
		this.hide()
		this.show()
		this.handleBehaviour();
	
	}
	}
	handleBehaviour(){
	
		if(control.time==this.deadLine){
			
			this.despawn()
			this.hide()
		
		}
		else if(this.deadLine-control.time<=10){
		
			this.score=2;	
			control.world[this.x][this.y].imageName="berryBrown"
		}
	
	}
	getScore(){
		
		return this.score;
	}
	despawn(){
	
		this.afloat=false;
	
	}
	
}

class EatenBerry extends DeadlyEntity{

	constructor(x,y,image){
	
		super(x,y,image);
	}

}
class SnakeModule extends DeadlyEntity {
	constructor(x,y) {
		super(x,y, IMAGE_NAME_SNAKE_HEAD);
	}
}

class Snake extends Actor {
	constructor(x, y) {
		super(x, y, IMAGE_NAME_SNAKE_HEAD);
		this.startTrailSize=4;
		this.maxStomachSize=3;
		this.dead=false;
		[this.movex, this.movey] = [1,0];
		this.body=[]
		this.stomach=[]
		
		for(let i=0;i<this.startSize;i++){
			
			this.body.push(
		[this.x-i,this.y]);
		
		}
		this.trailSize=this.startTrailSize
	}
	handleKey() {
		let k = control.getKey();
		if (k === null ||k===undefined)	// ignore
			;
		else if (typeof(k) === "string"){	// special command
			// special command
			let i=0
			i=1
			}
			//mesg("special command == " + k)
		else{	// change direction
			if(!k[2]){
			[this.movex, this.movey] = [k[0],k[1]];
			}
			else{
			this.shiftBody([k[0],k[1]]);
			
			
			}
			//mesg("change direction == " + k)
		}
	}
	shiftBody(key){
	this.hide()
	this.hideTrail()
		this.x+=key[0];
		this.y+=key[1]
		for(let i=0;i<this.body.length;i++){
		
			this.body[i][0]+=key[0];
			this.body[i][1]+=key[1]
		
		}
	this.show()
	this.renderTrail()
		
	
	}
	getFront(){
	
					  let p=this.checkPositionVar(this.x+this.movex,this.y+this.movey)
					 return p
	
	
	}
	handleBehaviour(){
		
		let vision=this.getFront()
		let frontObject=control.world[vision[0]][vision[1]]
		if(frontObject instanceof DeadlyEntity){
		
			this.die()
			return;
		}
		if(frontObject instanceof Edible){
		
			frontObject.hide()
			this.eat(frontObject)
			return;
		}
		}
		
	renderTrail(){
		let i=this.body.length-1;
		let j=0;
		if(this.body.length>0){
		
		for(;j<this.stomach.length;i--,j++){
			let pos=this.body[i]
			let current=control.world[pos[0]][pos[1]];
		current=new EatenBerry(pos[0],pos[1],this.stomach[j])
		}
		for(;j<this.body.length;i--,j++){
		let pos=this.body[i]
		let current=control.world[pos[0]][pos[1]];
		current=new SnakeModule(pos[0],pos[1])
			
		}
	}
	} 
	hideTrail(){                                                        
		if(this.body.length>0){
		for(let i=0;i<this.body.length;i++){
			let pos=this.body[i]
			control.world[pos[0]][pos[1]].hide()
		}
		}
		}
	updateTrail(){
	
		this.body.push(
		[this.x,this.y]
		)
		while(this.body.length>this.trailSize){
		this.body.shift()
		}
	
	
	}
	eat(berry){
		if(this.stomach.includes(berry.getColor())&&this.trailSize>=10){
			this.trailSize=parseInt(this.trailSize*0.5);
			
		
		
		}
		else{
		this.trailSize+=berry.getScore()
		for(let i=0;i<berry.getScore();i++){
		this.body.push(
		[this.x,this.y]
		)
		}
		}
		this.stomach.push(
		berry.getColor()
		)
	
		while(this.stomach.length>this.maxStomachSize){
		this.stomach.shift();
		}
	}
	move(dx,dy){
	
	
		this.hide();
		this.hideTrail();
		this.updateTrail();
		this.renderTrail()
		this.x += dx;
		this.y += dy;
		this.show();
	
	
	}
	animation(x, y) {
		this.handleKey();
		this.handleBehaviour()
		this.move(this.movex, this.movey);
		this.checkPosition()
		control.score=this.trailSize+1
	}
	
	die(){
		control.gameOver=true;
	}
}



// GAME CONTROL

class GameControl {
	constructor() {
		let c = document.getElementById('canvas1');
		control = this;	// setup global var
		this.key = 0;
		this.time = 0;
		this.nextBerriesTime=this.time+1+rand(11)
		this.pause=false;
		this.gameOver=false
		this.score=0;
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
			case 37: return [-1, 0,false];	// LEFT, O, J
			case 79: case 74: return [-1,0,true];
			case 38: return [0, -1,false];	// UP, Q, I
			case 81: case 73: return [0,-1,true];
			case 39: return [1, 0,false];	// RIGHT, P, L
			case 80: case 76: return [1,0,true];
			case 40: return [0,1,false];	// DOWN, A, K
			case 65: case 75: return [0,1,true];
			case 32: togglePause()
			case 0: return null;
		// http://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
		};	
	}
	setupEvents() {
		addEventListener("keydown", e => this.keyDownEvent(e), false);
		addEventListener("keyup", e => this.keyUpEvent(e), false);
		setInterval(() => this.animationEvent(), 1000 / ANIMATION_EVENTS_PER_SECOND);
	}
	animationEvent() {
	if(!(this.pause||this.gameOver)){
		getStats(this.time,this.score);
		this.time++;
		for(let x=0 ; x < WORLD_WIDTH ; x++)
			for(let y=0 ; y < WORLD_HEIGHT ; y++) {
				let a = this.world[x][y];
				if( a.atime < this.time ) {
					a.atime = this.time;
					a.animation(x, y);
					if(this.score>=GAME_ENDING_SCORE){
					
					this.gameOver=true;
					}
				}
			}
		if(this.time==this.nextBerriesTime){
		
			this.genBerries(1+rand(5))
			this.getNextBerriesTime();
		}
	}
	else if(this.gameOver){
	
		let result= document.getElementById("timer");
		result.innerHTML="Perdeste"
		let pauseButton=document.getElementById("pauseButton");
	 	pauseButton.style.display = "none";
		if(this.score>=GAME_ENDING_SCORE){
					
		result.innerHTML= "Ganhaste!!!!"+"\nThe time: "+ this.time+ "\nThe score: "+this.score
		
		}
	
	}
	}
	genBerries(num){
	for(let i=0;i<num;i++){
	let pos= [rand(70),rand(40)]
		let len= goodBerryColours.length;
		let colour= goodBerryColours[rand(len)]
		this.world[pos[0]][pos[1]]=new Berry(pos[0],pos[1],colour)
	
	}
	}
	getNextBerriesTime(){
	
	this.nextBerriesTime+=1+rand(10x)
	
	}
	keyDownEvent(e) {
		this.key = e.keyCode;
	}
	keyUpEvent(e) {
	}
}


// Functions called from the HTML page
function togglePause(){
	if(control===undefined){
		return;
		}
	if(control.pause){
	
		control.pause=false
	}
	else{
	
		let result= document.getElementById("timer");
		result.innerHTML= "PAUSADO!!!!!!!"
		control.pause=true;
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
function getStats(timeValue,score){

	let timer=document.getElementById("timer");
	timer.innerHTML="The time: "+ timeValue+ "\nThe score: "+parseInt(score)
}

function b1() { mesg("button1") }
function b2() { mesg("button2") }



