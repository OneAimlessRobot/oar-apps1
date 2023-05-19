

function sumArr(arr,pos){

	if(pos>=arr.length-1){
		return arr[arr.length-1]
	}
	else{
		return arr[pos] +sumArr(arr,pos+1)
	}


}

function main(){

	let x= [1,2,3,4,5,6,7,8,9,10]
	console.log(sumArr(x,0))
	
	
	
	


}
main()
