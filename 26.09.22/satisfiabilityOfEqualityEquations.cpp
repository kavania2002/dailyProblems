class Solution
{
public:
    int rr[26];
    bool equationsPossible(vector<string> &equations)
    {
        for (int i = 0; i < 26; i++)
            rr[i] = i;
        for (string &eq : equations)
        {
            if (eq[1] == '=')
            {
                int num1 = (eq[0] - 'a'), num2 = (eq[3] - 'a');
                rr[unionFind(num1)] = unionFind(num2);
            }
        }

        for (string &eq : equations)
        {
            if (eq[1] == '!')
            {
                int num1 = (eq[0] - 'a'), num2 = (eq[3] - 'a');
                if (unionFind(num1) == unionFind(num2))
                    return false;
            }
        }

        return true;
    }

    int unionFind(int x)
    {
        if (rr[x] != x)
            rr[x] = unionFind(rr[x]);
        return rr[x];
    }
};