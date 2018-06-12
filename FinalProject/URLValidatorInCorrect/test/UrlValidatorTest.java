

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.
	 
   String[] validScheme = new String[] {"http://", "ftp://", "https://"};
   String[] invalidScheme = new String[] {":////", "http./", "ht4://"}; 
   String[] validAuthorities = new String[] {"www.yahoo.com", "255.255.255.255", "0.0.0.0"};
   String[] invalidAuthoities = new String[] {"w.yahoo.com", "yaahhho.com", ":-9.yahoo.com"};
   String[] validPort = new String[] {":80", ":0", ""};
   String[] invalidPort = new String[] {":-95", ":q3", ":5srl6"};
   String[] validPaths = new String[] {"/test1", "/t123", ""};
   String[] invalidPaths = new String[] {"///test", "/test//*file", "/..//"};
   String[] queries = new String[] {"?action=view", "", "?action=edit&mode=up"};
   
   
   public UrlValidatorTest(String testName) {
      super(testName);
   }

  
  //Manual Testing 1 - 4 
   public void testManualTest01()
   {

		String[] head = {"http","https"};
		UrlValidator urlVal = new UrlValidator(head);
		// Valid URL
		//Test fails
		assertTrue(urlVal.isValid("http://www.espn.com"));
   }
   
   
   public void testManualTest02() {
	   String[] head = {"http","https"};
	   UrlValidator urlVal = new UrlValidator(head);
		//Valid URL
	   if(urlVal.isValid("https://www.yahoo.com")) {
			System.out.println("https://www.yahoo.com is a valid address");
		}
	   else {
			System.out.println("https://www.yahoo.com is not a valid address");
		}
   }
  
   public void testManualTest03() {
	   String[] head = {"http","https"};
		UrlValidator urlVal = new UrlValidator(head);
		// Invalid URL
		assertFalse(urlVal.isValid("httpwww.businsiider.com"));
	   
   }
   
   public void testManualTest04() {
		String[] head = {"http","https"};
		UrlValidator urlVal = new UrlValidator(head);
		//Valid URL
		if(urlVal.isValid("https/oregonate.du")) {
			System.out.println("https/oregonate.du is a valid address");
		}
		else {
			System.out.println("https/oregonate.du is not a valid address");
		}

   }
   
   //First Partition is the scheme, authority, path, and query portions of the url are all valid
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com/maps?client=safari"));
	 
   }
   
 //Second Partition is the scheme is invalid, but all other parts are valid
   public void testYourSecondPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("$://www.google.com/maps?client=safari"));  
   }

   //Third Partition is the authority is invalid, but all other parts are valid
   public void testYourThirdPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://.com/maps?client=safari"));
   }
   
   //Fourth Partition is the path is invalid, but all other parts are valid
   public void testYourFouthPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://www.google.com/ /maps?client=safari"));
   }
   
   //Fifth Partition is the query is invalid, but all other parts are valid
   public void testYourFifthPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://www.google.com/maps?client= safari"));
   }
   
   //Sixth Partition is more than one part of the URL is invalid
   public void testYourSixthPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("thisisinnowayavalidurl"));
   }
   
   public void testIsValid01()
   {
	   System.out.println("*******Valid URL testing starting*******");
	   
	   UrlValidator urlVal = new UrlValidator();
	   for(int i = 0; i < 3; i++) {
		   String scheme = validScheme[i];
		   String authority = validAuthorities[i];
		   String port = validPort[i];
		   String path = validPaths[i];
		   String query = queries[i];
		   
		   String url = scheme + authority + port + path + query;
		   if (urlVal.isValid(url)){
			   System.out.printf("%s is a valid string\n", url);
		   }
		   else {
			   System.out.printf("%s is not a valid string\n", url);
		   }
		   
	   }
	   System.out.println("*******Valid URL testing finished*******");
   }
  
   public void testIsValid02()
   {
	   System.out.println("*******Invalid URL testing starting*******");
	   
	   UrlValidator urlVal = new UrlValidator();
	   for(int i = 0; i < 3; i++) {
		   String scheme = invalidScheme[i];
		   String authority = invalidAuthoities[i];
		   String port = invalidPort[i];
		   String path = invalidPaths[i];
		   String query = queries[i];
		   
		   String url = scheme + authority + port + path + query;
		   if (urlVal.isValid(url)){
			   System.out.printf("%s is a valid string\n", url);
		   }
		   else {
			   System.out.printf("%s is not a valid string\n", url);
		   }
		   
	   }
	   System.out.println("*******Invalid URL testing finished*******");
   }
   
   public void testIsValid03()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String correctString = "http://www.google.com/maps?client=safari";
	   for(int i = 0; i < correctString.length(); i++)
	   {
		   String incorrectString = correctString.substring(0, i) + " " + correctString.substring(i, correctString.length());
		   boolean result = urlVal.isValid(incorrectString);
		   if(result)
		   {
			   System.out.print("Test Failed \n" + "TestURL: " + incorrectString + " Results: " + Boolean.toString(result) + '\n');
		   }
		   //assertTrue(result);
	   }

   }
 
}
