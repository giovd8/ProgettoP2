#ifndef CONTAINER
#define CONTAINER

//DEFINIZIONE container
template<class T>
class container {
    private:
        //DEFINIZIONE NODO
        class nodo {
            public:
                T info;
                nodo* prev;
                nodo* next;
                nodo(const T&, nodo* =nullptr, nodo* =nullptr);
                ~nodo();
        };
        //salvo puntatori a primo ed ultimo elemento per facilitare le push
        nodo* primo;
        nodo* ultimo;
     public:
        container(nodo* =nullptr, nodo* =nullptr);
        void pushBegin(const T&);
        void pushEnd(const T&);
        //DEFINIZIONE ITERATORE
        class iteratore {
            friend class container<T>;
            private:
                nodo* pt;
            public:
                iteratore();
                iteratore(nodo*);
                const T& operator*() const;
                const T* operator->() const;
                iteratore& operator++();
                iteratore& operator--();
                bool operator==(const iteratore&) const;
                bool operator!=(const iteratore&) const;
        };
        //DEFINIZIONE CONSTITERATORE
        class constIteratore {
            friend class container<T>;

        private:
            nodo *pt;

        public:
            constIteratore();
            constIteratore(nodo *);
            const T &operator*() const;
            const T *operator->() const;
            constIteratore &operator++();
            constIteratore &operator--();
            bool operator==(const constIteratore &) const;
            bool operator!=(const constIteratore &) const;
        };

        iteratore begin() const;
        iteratore end() const;
        constIteratore constBegin() const;
        constIteratore constEnd() const;
        void erase(iteratore);
};

//NODO: definizione costruttore e distruttore
template<typename T>
container<T>::nodo::nodo(const T &i, nodo *pv, nodo *nx) : info(i), prev(pv), next(nx){}

template<typename T>
container<T>::nodo::~nodo() {
    if(next)
        delete next;
}

//CONTAINER: definizione costruttore e metodi push
template<typename T>
container<T>::container(nodo *pr, nodo *ul) : primo(pr),ultimo(ul) {}

template<typename T>
void container<T>::pushBegin(const T &t) {
    primo=new nodo(t,nullptr,primo);
    if(ultimo==nullptr)
        ultimo=primo;
    else
        (primo->next)->prev=primo;
}

template<typename T>
void container<T>::pushEnd(const T &t) {
    ultimo=new nodo(t,ultimo,nullptr);
    if(primo==nullptr)
        primo=ultimo;
    else
        (ultimo->prev)->next=ultimo;
}

//ITERATORE: definizione costruttori ed overloading operatori
template<typename T>
container<T>::iteratore::iteratore():pt(nullptr){}

template<typename T>
container<T>::iteratore::iteratore(nodo* p):pt(p) {}

template<typename T>
const T& container<T>::iteratore::operator*() const {
    return pt->info;
}

template<typename T>
const T* container<T>::iteratore::operator->() const {
    return &(pt->info);
}

template<typename T>
typename container<T>::iteratore& container<T>::iteratore::operator++() {
    if(pt)
        pt=pt->next;
    return *this;
}

template<typename T>
typename container<T>::iteratore& container<T>::iteratore::operator--() {
    if(pt)
        pt=pt->prev;
    return *this;
}

template<typename T>
bool container<T>::iteratore::operator ==(const iteratore& i) const {
    return pt==i.pt;
}

template<typename T>
bool container<T>::iteratore::operator !=(const iteratore& i) const {
    return pt!=i.pt;
}

// CONSTITERATORE : definizione costruttori e overloading operatori
template <typename T>
container<T>::constIteratore::constIteratore() : pt(nullptr) {}

template <typename T>
container<T>::constIteratore::constIteratore(nodo *p) : pt(p) {}

template <typename T>
const T &container<T>::constIteratore::operator*() const {
    return pt->info;
}

template <typename T>
const T *container<T>::constIteratore::operator->() const {
    return &(pt->info);
}

template <typename T>
typename container<T>::constIteratore &container<T>::constIteratore::operator++() {
    if (pt)
        pt = pt->next;
    return *this;
}

template <typename T>
typename container<T>::constIteratore &container<T>::constIteratore::operator--() {
    if (pt)
        pt = pt->prev;
    return *this;
}

template <typename T>
bool container<T>::constIteratore::operator==(const constIteratore &i) const {
    return pt == i.pt;
}

template <typename T>
bool container<T>::constIteratore::operator!=(const constIteratore &i) const {
    return pt != i.pt;
}

// BEGIN/END ITERATORI
template <typename T>
typename container<T>::iteratore container<T>::begin() const
{
    return iteratore(primo);
}

template <typename T>
typename container<T>::iteratore container<T>::end() const
{
    return iteratore(ultimo->next);
}

template <typename T>
typename container<T>::constIteratore container<T>::constBegin() const
{
    return constIteratore(primo);
}

template <typename T>
typename container<T>::constIteratore container<T>::constEnd() const
{
    return constIteratore(ultimo->next);
}

// ERASE ITERATORE
template <typename T>
void container<T>::erase(iteratore it)
{
    if (!it.pt->next && !it.pt->prev)
    {
        primo = nullptr;
        ultimo = nullptr;
    }
    else
    {
        if (!it.pt->next)
        {
            ultimo = it.pt->prev;
        }

        if (!it.pt->prev)
        {
            primo = it.pt->next;
        }

        if (it.pt->next && it.pt->prev)
        {
            (it.pt->prev)->next = it.pt->next;
            (it.pt->next)->prev = it.pt->prev;
        }
    }
}

#endif // container

