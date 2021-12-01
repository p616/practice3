/**
 * 
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
        boolean result = isSimilarSentence(Arrays.asList("sale", "today", "on", "dog", "food"),
                                          Arrays.asList("sale", "today", "on", "canine", "eats"),
                                          Arrays.asList(new SimilarityPair("canine", "dog"), new SimilarityPair("food", "eats")));
        
    }
    
    public static boolean isSimilarSentence(List<String> sentence1, List<String> sentence2, List<SimilarityPair> similarities) {

    }
    static class SimilarityPair {
        private final String word1;
        private final String word2;

        public SimilarityPair(String word1, String word2) {
            this.word1 = word1;
            this.word2 = word2;
        }

        public String getWord1() {
            return word1;
        }

        public String getWord2() {
            return word2;
        }
    }
}
 */


/**
const numbers = [65, 44, 12, 4];
numbers.forEach(myFunction)

function myFunction(item, index, arr) {
  arr[index] = item * 10;
}
 */

function isSimilarSentence(s1, s2, similarList) {
    if (s1.length !== s2.length) {
        return false;
    }
    
    let simMap = new Map();
    for (let index2 = 0; index2 < similarList.length; ++index2) { 
        //simMap.set(similarList[index2][0], similarList[index2][1]);
        if (simMap.has(similarList[index2][0])) {
            let simSet = simMap.get(similarList[index2][0]);
            simSet.add(similarList[index2][1]);
            //console.log(`creating ${} ${}`);
        } else {
            let simSet = new Set();
            simSet.add(similarList[index2][1]);
            simMap.set(similarList[index2][0], simSet);
        }
    }
    
    for (let index = 0; index < s1.length; ++index) {
        if (s1[index] === s2[index]) {
            continue;
        }
        if (simMap.has(s1[index])) {
            let simSet = simMap.get(s1[index]);
            if (simSet.has(s2[index])) {
                continue;
            }
            else {
                return false;
            }
        }
        /*
        if (simMap.get(s1[index]) === s2[index] || 
            simMap.get(s2[index]) === s1[index] ) {
                continue;
        }
        else {
            return false;
        }
        */
        /*
        for (let index2 = 0; index2 < sililarList.length; ++index2) { 
             if ((similarList[index2][0] === s1[index] && sililarList[index2][1] === s2[index]) || 
                (similarList[index2][0] === s2[index] && sililarList[index2][1] === s1[index])) {
                    continue;
                }
                else {
                    return false;
                }
        }
        */
    }            
    
    return true;    
}

let sent1 = new Array("sale", "today", "on", "dog", "food");
let sent2 = new Array("sale", "today", "on", "canine", "eats");
let sims = new Array(["dog", "snoopy"], ["dog", "canine"], ["food", "eats"]);
let ret = isSimilarSentence(sent1, sent2, sims);
console.log(ret);



