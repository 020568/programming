#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Segment tree and lazy propagation arrays
int tree[MAX] = { 0 };
int lazy[MAX] = { 0 };

/**
 * Update a range of values using Lazy Propagation
 * si: Current node index in segment tree
 * ss & se: Starting and ending indices of the current segment
 * us & ue: Starting and ending indices of the update range
 * diff: Value to be added to the range
 */
void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
    // 1. Handle pending updates before proceeding
    if (lazy[si] != 0) {
        // Update the current node's sum
        tree[si] += (se - ss + 1) * lazy[si];

        // If not a leaf node, propagate the lazy value to children
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }

        // Reset the lazy value for the current node
        lazy[si] = 0;
    }

    // Out of range: no overlap
    if (ss > se || ss > ue || se < us)
        return;

    // 2. Current segment is fully within the update range
    if (ss >= us && se <= ue) {
        // Update the current node
        tree[si] += (se - ss + 1) * diff;

        // If not a leaf node, postpone updating children by storing in lazy array
        if (ss != se) {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    // 3. Partial overlap: recur for left and right children
    int mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

    // After children updates, update current node sum
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

/**
 * Wrapper for updateRangeUtil
 */
void updateRange(int n, int us, int ue, int diff) {
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

/**
 * Get the sum of elements in a given range
 * qs & qe: Starting and ending indices of the query range
 */
int getSumUtil(int ss, int se, int qs, int qe, int si) {
    // 1. Handle pending updates
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    // Out of range
    if (ss > se || ss > qe || se < qs)
        return 0;

    // 2. Fully within range: return node value
    if (ss >= qs && se <= qe)
        return tree[si];

    // 3. Partial overlap
    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

/**
 * Wrapper for getSumUtil with error checking
 */
int getSum(int n, int qs, int qe) {
    if (qs < 0 || qe > n - 1 || qs > qe) {
        printf("Invalid Input\n");
        return -1;
    }
    return getSumUtil(0, n - 1, qs, qe, 0);
}

/**
 * Construct the segment tree from an array
 */
void constructSTUtil(int arr[], int ss, int se, int si) {
    if (ss > se) return;

    // Leaf node
    if (ss == se) {
        tree[si] = arr[ss];
        return;
    }

    // Internal node: store sum of children
    int mid = (ss + se) / 2;
    constructSTUtil(arr, ss, mid, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, si * 2 + 2);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

/**
 * Wrapper for constructSTUtil
 */
void constructST(int arr[], int n) {
    constructSTUtil(arr, 0, n - 1, 0);
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build the initial segment tree
    constructST(arr, n);

    // Initial query
    printf("Sum of values in range [1, 3] = %d\n", getSum(n, 1, 3));

    // Update range [1, 5] by adding 10 to each element
    updateRange(n, 1, 5, 10);

    // Query after update
    printf("Updated sum of values in range [1, 3] = %d\n", getSum(n, 1, 3));

    return 0;
}