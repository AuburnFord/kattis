import java.util.*;
import java.io.*;

public class PathTracing{
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int lowest = 0;
        int highest = 0;
        int leftest = 0;
        int rightest = 0;
        int x = 0;
        int y = 0;
        String[] instr = new String[500];
        int index = 0;
        String next = in.readLine();
        while (next != null) {
            instr[index++] = next;
            switch (next) {
                case "left": 
                    x -= 1;
                    break;
                case "right": 
                    x+= 1;
                    break;
                case "down": 
                    y+= 1;
                    break;
                case "up": 
                    y-=1;
                    break;
            }
            if (lowest < y) {
                lowest = y;
            }
            if (highest > y) {
                highest = y;
            }
            if (leftest > x) {
                leftest = x;
            }
            if (rightest < x) {
                rightest = x;
            }
            next = in.readLine();
        }
        int xSize = rightest - leftest +3;
        int ySize = lowest - highest +3;
        char map[][] = new char[ySize][xSize];
        for (int i = 0; i < ySize; i++) {
            for (int j = 0; j < xSize; j++) {
                map[i][j] = ' ';
            }
        }
        for (int i = 0; i < xSize; i++) {
            map[0][i] = '#';
            map[ySize-1][i] = '#';
        }
        for (int i = 0; i < ySize; i++) {
            map[i][0] = '#';
            map[i][xSize-1] = '#';
        }
        int startX = 0 - leftest + 1;
        int startY = 0 - highest + 1;
        map[startY][startX] = 'S';
        for (int i = 0; i < index; i++) {
            switch (instr[i]) {
                case "left": 
                    startX -= 1;
                    break;
                case "right": 
                    startX+= 1;
                    break;
                case "down": 
                    startY+= 1;
                    break;
                case "up": 
                    startY-=1;
                    break;
            }
            if (map[startY][startX] != 'S') map[startY][startX] = '*';
        }
        map[startY][startX] = 'E';
        for (int i = 0; i < ySize; i++) {
            for (int j = 0; j < xSize; j++) {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
}