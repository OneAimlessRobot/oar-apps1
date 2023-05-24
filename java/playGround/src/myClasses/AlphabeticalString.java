package myClasses;

public class AlphabeticalString implements Comparable<AlphabeticalString>{
	private String value;
	public AlphabeticalString(String str) {
		
		char[] arr= str.toCharArray();
		if(!str.isEmpty()) {
			Character c= Character.valueOf(str.charAt(0));
			c=Character.toUpperCase(c);
			arr[0]=c;
			
		}
		setValue(String.copyValueOf(arr));
		value.replaceAll("\\P{Print}", "");
	}
	public int getLength() {
		
		return this.value.length();
	}
	public boolean equals(AlphabeticalString str) {
		System.out.println(this.value.length()+" "+str.value.length());
		return this.value.equals(str.value);
		
		
	}
	public String getValue() {
		return value;
	}
	public void setValue(String value) {
		this.value = value;
	}
	public int hashCode() {
		
		return (int) value.charAt(0);
	}
	public String toString() {
		return this.value;
	}
	@Override
	public int compareTo(AlphabeticalString arg0) {
	
		return this.value.compareTo(arg0.value);
	}
	
}
