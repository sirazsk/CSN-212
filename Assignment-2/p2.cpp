import java.util.*;

public class AvoidRoads
{
	public long numWays(int w, int h, String[] bad)
	{
		w++; h++;

		Set<String> b = new TreeSet<String>();
		for(int i = 0;i < bad.length;i++)
			b.add(bad[i]);

		long[][] dp = new long[w][h];

		for(int i = 0;i < w;i++)
		{
			for(int j = 0;j < h;j++)
			{
				if(i == 0 && j == 0)
				{
					dp[i][j] = 1;
					continue;
				}
				if(i > 0)
				{
					String move = (i-1) + " " + j + " " + i + " " + j;
					String move2 = i + " " + j + " " + (i-1) + " " + j;
					if(!b.contains(move) && !b.contains(move2)) dp[i][j] += dp[i-1][j];
				}
				if(j > 0)
				{
					String move = i + " " + (j-1) + " " + i + " " + j;
					String move2 = i + " " + j + " " + i + " " + (j-1);
					if(!b.contains(move) && !b.contains(move2)) dp[i][j] += dp[i][j-1];
				}
			}
		}

		return dp[w-1][h-1];
	}
}
