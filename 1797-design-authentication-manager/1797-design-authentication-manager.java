class AuthenticationManager {
    HashMap<String,Integer> tada = new HashMap<>();
    int ttl;

    public AuthenticationManager(int timeToLive) {
        this.ttl = timeToLive;
    }
    
    public void generate(String tokenId, int currentTime) {
        tada.put(tokenId, currentTime + ttl);
            // tada[] = sjdfkjsd
        }
    
    public void renew(String tokenId, int currentTime) {
        Integer endTime = tada.get(tokenId);
        if(endTime != null && endTime>currentTime){
            tada.put(tokenId, currentTime + ttl);
        }
    }
    
    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(Map.Entry<String,Integer> boombaya : tada.entrySet()){
            if(boombaya.getValue() > currentTime){
                count++;
            }
        }
        return count;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */