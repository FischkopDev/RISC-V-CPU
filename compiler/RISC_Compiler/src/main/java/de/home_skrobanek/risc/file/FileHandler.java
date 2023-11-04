package de.home_skrobanek.risc.file;

import java.io.*;

public class FileHandler {

    private File file;

    public FileHandler(File file){
        this.file = file;
    }

    public String read(){
        try{
            String content = "";

            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            String line;
            while((line = br.readLine()) != null){
                content += line + "\n";
            }

            br.close();

            return content;
        }catch(IOException ex){
            ex.printStackTrace();
        }
        return null;
    }

    public String replace(String key, String value, String content){
        return content.replace(key, value);
    }

    public void write(String content, boolean append){
        try{
            FileWriter fw = new FileWriter(file, append);
            BufferedWriter bw = new BufferedWriter(fw);

            bw.write(content);

            bw.close();
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }

    public String removeSubstringBetween(String input, String start, String end) {
        int startIndex = input.indexOf(start);

        while (startIndex != -1) {
            int endIndex = input.indexOf(end, startIndex + start.length());

            if (endIndex != -1) {
                // Extract the substring before and after the part to be removed
                String partBefore = input.substring(0, startIndex);
                String partAfter = input.substring(endIndex + end.length());

                // Combine the parts, including the start and end strings, to create the modified string
                input = partBefore + start + end + partAfter;

                // Find the next occurrence of the start string
                startIndex = input.indexOf(start, startIndex + start.length() + end.length());
            } else {
                // If the end string is not found, break the loop
                break;
            }
        }

        return input;
    }

    public String removeEmptyLines(String input) {
        String[] lines = input.split("\\n"); // Split the input into lines

        StringBuilder result = new StringBuilder();

        for (String line : lines) {
            if (!line.trim().isEmpty()) {
                // If the line is not empty, add it to the result
                result.append(line).append("\n");
            }
        }

        // Remove the trailing newline character (if present)
        if (result.length() > 0) {
            result.setLength(result.length() - 1);
        }

        return result.toString();
    }


        public void write(String content, boolean append, File tmp){
        try{
            if(!tmp.exists())
                tmp.createNewFile();

            FileWriter fw = new FileWriter(tmp, append);
            BufferedWriter bw = new BufferedWriter(fw);

            bw.write(content);

            bw.close();
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }

    public boolean existsFile(){
        return file.exists();
    }
}
