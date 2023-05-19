
def sumList(array,pos):
	if pos == len(array)-1:
		return array[pos]
	else:
		return array[pos]+sumList(array,pos+1)


def main():
	list=[1,2,3,4,5,6,7,8,9,10]
	print(sumList(list,1))


main()
