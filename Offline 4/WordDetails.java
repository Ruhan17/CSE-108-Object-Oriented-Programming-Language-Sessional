/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafx_offline;

/**
 *
 * @author HP
 */
public class WordDetails {
    
    String word;
    int frequency;
    
    WordDetails(String w,int f){
        word = w;
        frequency = f;
    }
    
    public String getWord() {
        return word;
    }

    public int getFrequency() {
        return frequency;
    }
    
    public void setName(String word) {
        this.word = word;
    }

    public void setId(int frequency) {
        this.frequency = frequency;
    }

    
}
