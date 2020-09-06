import java.io.*;
import java.util.*;

class TestClass
{
    void solve() throws Exception
    {
        System.out.println("hello");
        int n;
        //n = ni();
        //int a[] = new int[n];
        //for(int i=0;i<n;i++)
           // a[i]=ni();
    }
    FastReader in;PrintWriter out;
    void init() throws Exception
    {
        in = new FastReader();
	    out = new PrintWriter(System.out);
        int t;
        t=ni();
        for(int i=0;i<t;i++)
            solve();
        out.flush();
        out.close();
    }
    public static void main(String argv[]) throws Exception
    {
        new TestClass().init();
    }

    void pn(Object o)
    {
        out.println(o);
    }
    int ni()throws Exception{
        return Integer.parseInt(in.next());
    }
	long nl()throws Exception{
	    return Long.parseLong(in.next());
	}

    class FastReader
    {
    	    BufferedReader br;
    	    StringTokenizer st;
    	    public FastReader(){
    	        br = new BufferedReader(new InputStreamReader(System.in));
    	    }

    	    public FastReader(String s) throws Exception{
    	        br = new BufferedReader(new FileReader(s));
    	    }

    	    String next() throws Exception{
    	        while (st == null || !st.hasMoreElements()){
    	            try{
    	                st = new StringTokenizer(br.readLine());
    	            }catch (IOException  e){
    	                throw new Exception(e.toString());
    	            }
    	        }
    	        return st.nextToken();
    	    }

    	    String nextLine() throws Exception{
    	        String str = "";
    	        try{
    	            str = br.readLine();
    	        }catch (IOException e){
    	            throw new Exception(e.toString());
    	        }
    	        return str;
    	    }
	}
}
