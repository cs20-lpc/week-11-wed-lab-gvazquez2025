template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    int probes = 0;

    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;

        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            N++;
            return probes;
        }
    }

    throw runtime_error("Hash table is full");
}
  //  return 0;
//}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    int probes = 0;

    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;

        if (!occupied[idx])
            return {false, probes};

        if (occupied[idx] && table[idx] == key)
            return {true, probes};
    }

    return {false, probes};
    return {false, 0};
} 
   
