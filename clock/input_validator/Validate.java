import java.io.*;
import java.util.*;

public class Validate {
  final int MAXK = 100;
  final int MAXN = 100;
  final int MAXM = 100;

  public void run() {
    StrictScanner inf = new StrictScanner(System.in);
    int k = inf.nextInt();
    int n = inf.nextInt();
    int m = inf.nextInt();
    inf.nextLine();
    ensureLimits(k, 1, MAXK, "k");
    ensureLimits(n, 1, MAXN, "n");
    ensureLimits(m, 1, MAXM, "m");
    for (int i = 0; i < k * n; i++) {
      String s = inf.next();
      inf.nextLine();
      ensure(s.length() == m, "length of " + (i + 1) + "-th line is wrong");
      for (int j = 0; j < m; j++) {
        ensure(
            s.charAt(j) == '.' || s.charAt(j) == '*', "chars of " + (i + 1) + "-th line are wrong");
      }
    }
    inf.close();
  }

  public static void main(String[] args) {
    new Validate().run();
    return 42;
  }

  public class StrictScanner {
    private final BufferedReader in;
    private String line = "";
    private int pos;
    private int lineNo;

    public StrictScanner(InputStream source) {
      in = new BufferedReader(new InputStreamReader(source));
      nextLine();
    }

    public void close() {
      ensure(line == null, "Extra data at the end of file");
      try {
        in.close();
      } catch (IOException e) {
        throw new AssertionError("Failed to close with " + e);
      }
    }

    public void nextLine() {
      ensure(line != null, "EOF");
      ensure(pos == line.length(), "Extra characters on line " + lineNo);
      try {
        line = in.readLine();
      } catch (IOException e) {
        throw new AssertionError("Failed to read line with " + e);
      }
      pos = 0;
      lineNo++;
    }

    public String next() {
      ensure(line != null, "EOF");
      ensure(line.length() > 0, "Empty line " + lineNo);
      if (pos == 0) ensure(line.charAt(0) > ' ', "Line " + lineNo + " starts with whitespace");
      else {
        ensure(pos < line.length(), "Line " + lineNo + " is over");
        ensure(line.charAt(pos) == ' ', "Wrong whitespace on line " + lineNo);
        pos++;
        ensure(pos < line.length(), "Line " + lineNo + " is over");
        ensure(line.charAt(0) > ' ', "Line " + lineNo + " has double whitespace");
      }
      StringBuilder sb = new StringBuilder();
      while (pos < line.length() && line.charAt(pos) > ' ') sb.append(line.charAt(pos++));
      return sb.toString();
    }

    public int nextInt() {
      String s = next();
      ensure(
          s.length() == 1 || s.charAt(0) != '0',
          "Extra leading zero in number " + s + " on line " + lineNo);
      ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s + " on line " + lineNo);
      try {
        return Integer.parseInt(s);
      } catch (NumberFormatException e) {
        throw new AssertionError("Malformed number " + s + " on line " + lineNo);
      }
    }

    public long nextLong() {
      String s = next();
      ensure(
          s.length() == 1 || s.charAt(0) != '0',
          "Extra leading zero in number " + s + " on line " + lineNo);
      ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s + " on line " + lineNo);
      try {
        return Long.parseLong(s);
      } catch (NumberFormatException e) {
        throw new AssertionError("Malformed number " + s + " on line " + lineNo);
      }
    }

    public double nextDouble() {
      String s = next();
      ensure(
          s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0',
          "Extra leading zero in number " + s + " on line " + lineNo);
      ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s + " on line " + lineNo);
      try {
        return Double.parseDouble(s);
      } catch (NumberFormatException e) {
        throw new AssertionError("Malformed number " + s + " on line " + lineNo);
      }
    }
  }

  void ensure(boolean b, String message) {
    if (!b) {
      throw new AssertionError(message);
    }
  }

  void ensureLimits(long n, long from, long to, String name) {
    ensure(from <= n && n <= to, name + " must be from " + from + " to " + to);
  }

  void ensureLimits(int n, int from, int to, String name) {
    ensure(from <= n && n <= to, name + " must be from " + from + " to " + to);
  }
}
