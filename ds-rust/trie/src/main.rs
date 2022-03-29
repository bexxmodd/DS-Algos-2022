use std::collections::HashMap;

#[derive(Debug, Clone)]
struct Node {
    character: char,
    children: HashMap<char, Node>,
    is_end: bool,
}

impl Node {
    fn new(character: char) -> Self {
        Node {
            character,
            children: HashMap::<char, Node>::new(),
            is_end: false,
        }
    }
}

#[derive(Debug)]
struct Trie {
    root: Node,
}

impl Trie {
    fn new() -> Self {
        Trie {
            root: Node::new('\0')
        }
    }

    fn insert(&mut self, word: String) {
        let mut node = self.root.clone();
        word.chars().for_each(|ch|
            { node = node.children.entry(ch)
                         .or_insert(Node::new(ch))
                         .clone(); }
        );
        node.is_end = true;
    }
}

fn main() {
    let mut trie = Trie::new();
    trie.insert("beka".to_string());
    println!("{:?}", trie);
}
