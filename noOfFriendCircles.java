public class Main
{
    public static void findFriends(char[][] friends, boolean[] visited, int frnd){
        for(int i=0;i<friends.length;i++){
            if(!visited[i] && friends[frnd][i]=='Y'){
                visited[i]=true;
                findFriends(friends,visited,i);
            }
        }
    }
    public static int getFriendCircles(char[][] friends){
        if(friends == null || friends.length < 1)
            return 0;
        int noOfCircles = 0;
        boolean visited[] = new boolean[friends.length];
        for(int i=0;i<friends.length;i++)
            visited[i]=false;
        for(int i=0;i<friends.length;i++){
            if(!visited[i]){
                noOfCircles++;
                visited[i]=true;
                findFriends(friends,visited,i);
            }
        }
        return noOfCircles;
    }
	public static void main(String[] args) {
		char[][] friends={{'Y','Y','N','N'},{'Y','Y','Y','N'},{'N','Y','Y','N'},{'N','N','N','Y'}};
		System.out.println(getFriendCircles(friends));
	}
}
