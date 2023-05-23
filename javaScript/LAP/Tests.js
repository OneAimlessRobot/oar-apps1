//Prototipos:

class Succ{

 	constructor(value){

		this.init=this.current=value
		
	
	


	}
	first(){
		this.current=this.init
		return this.init
		
	
	}
	at(i){
		let k=0;	
		for(let j=0;j<i;j++){
	
			k=this.next()
		}
		this.first(this.init)
		return k
	}
	print(i){

		
                for(let j=0;j<i;j++){

                        
			console.log(this.next())
                }
                this.first(this.init)
	}
	

}
class Arith extends Succ{
	
	
	constructor(init,inc){

	super(init)
		
	this.inc=inc

	}
	next(){

		this.current+=this.inc
		return this.current
	
	}
	
	
	
	

}
class Geo extends Succ{

	constructor(init,mult){
	
	super(init)
	this.mult=mult

		
	}
	next(){

                this.current*=this.mult
		return this.current
        }


}

class SuperArith extends Arith{

	at(i){

		return this.init+this.inc*i;
	}




}

class DualSucc extends Succ{

	constructor(succ1,succ2){
		
		super(succ1.first()+succ2.first())
		this.succ1=succ1
		this.succ2=succ2

	}
	first(){

		this.succ2.first()
		this.succ1.first()
	}
	next(){
		
		this.current= this.succ1.next()+this.succ2.next()
		return this.current
	}
	

}
class AltSucc extends Succ{
	
	constructor(succ1,succ2){
		super(succ1.first());
		this.succ1=succ1
		this.succ2=succ2
		this.isFirst=true
		
	}
	first(){
		this.succ2.first()
		this.succ1.first()
		
	}
	next(){
		if(this.isFirst){
			this.current= this.succ1.next()
			this.isFirst=false
			return this.current
			
		}
		else{
			this.current=this.succ2.next()
			this.isFirst=true
			return this.current
		}
		
	
	}





}
class Filter extends Succ{

        constructor(succ1,filter){
                super(succ1.first());
                this.succ1=succ1
		this.filter=filter

        }
        first(){
         
                while(this.current%this.filter!=0){
			
			this.current=this.succ1.next()
		}
        
	}
        next(){
                
		this.skipBad()
		return this.current
		

        }
	
	skipBad(){


		 while(this.current%this.filter!=0){

                        this.current=this.succ1.next()
                }
	

	}




}


class Const extends Succ{


	next(){return this.init}
}
console.log("HEEEHHEHEHEHEH")

let j = new SuperArith(1,1)

let k= new Filter(j,3)

k.print(8)
