class Solution {
    public String removeVowels(String s) {
        String answer = "";
        HashSet<Character> bubu= new HashSet<>();
        bubu.add('a');
        bubu.add('e');
        bubu.add('i');
        bubu.add('o');
        bubu.add('u');
        for(Character c:s.toCharArray()){
            if(!bubu.contains(c)){
                answer += String.valueOf(c);
            }
        }
        return answer;
    }
}