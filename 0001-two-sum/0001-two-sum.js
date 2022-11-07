/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  for (var i = 0; i < nums.length; i++) {
    const ind = nums.findIndex(function (e) {
      return e === target - nums[i];
    });
    if (ind !== -1 && ind !== i) return Array(i, ind);
  }
};
