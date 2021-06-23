
#include <vector>

using namespace std;

/*
 * 你正在经营一座摩天轮，该摩天轮共有 4 个座舱 ，每个座舱 最多可以容纳 4 位游客 。 => 共容纳 16 人
 * 你可以逆时针轮转座舱，但每次轮转都需要支付一定的运行成本 runningCost 。摩天轮每次轮转都恰好转动 1 / 4 周。 => 转一圈儿 4 * runningCost
 * 
 * 给你一个长度为 n 的数组 customers ， customers[i] 是在第 i 次轮转（下标从 0 开始）之前到达的新游客的数量。
 * 这也意味着你必须在新游客到来前轮转 i 次。每位游客在登上离地面最近的座舱前都会支付登舱成本 boardingCost ，一旦该座舱再次抵达地面，他们就会离开座舱结束游玩。
 * 
 * 你可以随时停下摩天轮，即便是 在服务所有游客之前 。
 * 如果你决定停止运营摩天轮，为了保证所有游客安全着陆，将免费进行所有后续轮转 。
 * 注意，如果有超过 4 位游客在等摩天轮，那么只有 4 位游客可以登上摩天轮，其余的需要等待 下一次轮转 。
 * 
 * 返回最大化利润所需执行的 最小轮转次数 。 如果不存在利润为正的方案，则返回 -1 。
 * 
 * 输入：customers = [8,3], boardingCost = 5, runningCost = 6
 * 输出：3
 * 解释：座舱上标注的数字是该座舱的当前游客数。
 * 1. 8 位游客抵达，4 位登舱，4 位等待下一舱，摩天轮轮转。当前利润为 4 * $5 - 1 * $6 = $14 。
 * 2. 3 位游客抵达，4 位在等待的游客登舱，其他 3 位等待，摩天轮轮转。当前利润为 8 * $5 - 2 * $6 = $28 。
 * 3. 最后 3 位游客登舱，摩天轮轮转。当前利润为 11 * $5 - 3 * $6 = $37 。
 * 轮转 3 次得到最大利润，最大利润为 $37 。
 * 
 * 这道题有点儿类似于恰苹果那道，树上结了苹果，过几天苹果就会烂掉。
 * 
 * 🎡 的转动随着 customers 数组的遍历而进行，只能纯模拟运行了
 */

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();

        int maxProfile = -1, minOperation = -1;
        int profile = 0, count = 0, index = 0, waiting = 0;


        while (index < n || waiting > 0) {

            // 添加等待人数
            if (index < n) {
                waiting += customers[index];
                index ++;
            }

            // 装载
            if (waiting > 0) {
                profile += min(4, waiting) * boardingCost;
                waiting -= min(4, waiting);
            }

            // 不管装没装人，都得转
            count ++;
            profile -= runningCost;

            // 计算最大利润
            if (profile > maxProfile) {
                maxProfile = profile;
                minOperation = count;
            }
        }

        return maxProfile > 0 ? minOperation : -1;

    }
};