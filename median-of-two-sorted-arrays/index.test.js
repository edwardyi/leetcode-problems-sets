const findMedianSortedArrays = require('./index.js');

test('find middle number from two sorted array', () => {
    expect(findMedianSortedArrays([], [3, 4])).toBe(3.5);
    expect(findMedianSortedArrays([], [3, 4, 5])).toBe(4);
    expect(findMedianSortedArrays([], [3, 4, 5, 6])).toBe(4.5);
    expect(findMedianSortedArrays([3, 4, 5, 6], [])).toBe(4.5);
    expect(findMedianSortedArrays([1, 2], [3, 4])).toBe(2.5);
    expect(findMedianSortedArrays([1, 2, 3], [3, 4])).toBe(3);
    expect(findMedianSortedArrays([1, 2, 3], [3, 4, 5])).toBe(3);
    expect(findMedianSortedArrays([1, 2, 3, 6], [3, 4, 5])).toBe(3);
    expect(findMedianSortedArrays([2], [1, 3])).toBe(2);
});