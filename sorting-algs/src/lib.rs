#[allow(unused_imports)]
use rand::prelude::SliceRandom;
use std::fmt::Debug;

pub trait Sorting {
    type Item: Ord + Copy + Debug;
    fn insertion_sort(&mut self);
    fn bubble_sort(&mut self);

    fn quick_sort(&mut self);
    fn _qsort(&mut self, start: isize, end: isize);
    fn partition(&mut self, start: isize, end: isize) -> isize;

    fn heap_sort(&mut self);
    fn heapify(&mut self);
    fn sift_up(&mut self, start: usize, end: usize);
    fn parent(&self, i: usize) -> usize;
}

impl<T> Sorting for [T]
where 
    T: Ord + Copy + Debug
{
    type Item = T;

    fn insertion_sort(&mut self) {
        for i in 1..self.len() {
            let curr = self[i];
            let mut hole = i;
            while hole > 0 && self[hole - 1] > curr {
                self[hole] = self[hole - 1];
                hole -= 1;
            }
            self[hole] = curr;
        }
    }

    fn bubble_sort(&mut self) {
        let len = self.len();
        for i in 0..len {
            let mut sorted = true;
            for j in 0..(len - i - 1) {
                if self[j] > self[j + 1] {
                    self.swap(j, j + 1);
                    sorted = false;
                }
            }
            if sorted { return }
        }
    }

    fn quick_sort(&mut self) {
        self._qsort(0, self.len() as isize - 1);
    }

    fn _qsort(&mut self, start: isize, end: isize) {
        if start < end {
            let pivot: isize = self.partition(start, end);
            self._qsort(start, pivot - 1);
            self._qsort(pivot + 1, end);
        }
    }

    fn partition(&mut self, start: isize, end: isize) -> isize {
        let pivot = self[end as usize];
        let mut index = start;
        for i in start..end {
            if self[i as usize] <= pivot {
                self.swap(i as usize, index as usize);
                index += 1;
            }
        }
        self.swap(index as usize, end as usize);
        index
    }

    fn heap_sort(&mut self) {
        self.heapify();
        let mut end = self.len() - 1;
        while end > 0 {
            println!("{:?}", self);
            self.swap(end, 0);
            self.heapify();
            end -= 1;
        }
    }

    fn heapify(&mut self) {
        let mut end = 1;
        while end < self.len() {
            self.sift_up(0, end);
            end += 1;
        }
    }

    fn sift_up(&mut self, start: usize, end: usize) {
        let mut child = end;
        while child > start {
            let parent = self.parent(child);
            if self[parent] < self[child] {
                self.swap(parent, child);
                child = parent;
            } else {
                return;
            }
        }
    }

    fn parent(&self, i: usize) -> usize {
        (i - 1) / 2
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn insertion_sort() {
        let mut v = vec![3, 2, 4, 1, 6, 8, 7, 5];
        v.insertion_sort();
        assert_eq!(v, vec![1, 2, 3, 4, 5, 6, 7, 8]);
    }

    #[test]
    fn bubble_sort() {
        let mut v = vec![3, 2, 4, 1, 6, 8, 7, 5];
        v.bubble_sort();
        assert_eq!(v, vec![1, 2, 3, 4, 5, 6, 7, 8]);
    }

    #[test]
    fn quick_sort_empty() {
        let mut v: Vec<i32> = vec![];
        v.quick_sort();
        assert_eq!(v, vec![]);
    }

    #[test]
    fn quick_sort_with_one_item() {
        let mut v = vec![3];
        v.quick_sort();
        assert_eq!(v, vec![3]);
    }

    #[test]
    fn quick_sort_with_two_items() {
        let mut v = vec![5, 4];
        v.quick_sort();
        assert_eq!(v, vec![4, 5]);
    }

    #[test]
    fn quick_sort_large_vec() { 
        let mut v = vec![3, 2, 0, 4, 1, 6, 8, 7, 5, 9];
        v.quick_sort();
        assert_eq!(v, vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
    }

    #[test]
    fn quick_sort_very_large() {
        let mut v: Vec<usize> = (0..10_000).collect();
        let mut rng = rand::thread_rng();
        v.shuffle(&mut rng);
        v.quick_sort();
        assert_eq!(v, (0..10_000).collect::<Vec<usize>>());
    }

    #[test]
    fn heap_sort_large_vec() { 
        let mut v = vec![3, 2, 0, 4, 1, 6, 8, 7, 5, 9];
        v.heap_sort();
        assert_eq!(v, vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
    }
}
