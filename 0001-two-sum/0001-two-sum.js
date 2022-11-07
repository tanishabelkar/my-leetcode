/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let dic = new Map();
  nums.forEach((n, i) => {
    dic.set(n, i);
  });

  let ans = [];

  nums.forEach((n, i) => {
    if (dic.has(target - n) && dic.get(target - n) !== i) {
      ans = Array(i, dic.get(target - n));
    }
  });
  return ans;
};
