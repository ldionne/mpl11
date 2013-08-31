
//// interesting experiment?
template <typename Iterator>
struct iterator_iterator {
    using category = typename category_of<Iterator>::type;
    using next = iterator_iterator<typename next<Iterator>::type>;
    using prior = iterator_iterator<typename prior<Iterator>::type>;
    using deref = Iterator;
};

template <typename Sequence>
struct iterator_view {
    using begin = iterator_iterator<typename begin<Sequence>::type>;
    using end = iterator_iterator<typename end<Sequence>::type>;
};
