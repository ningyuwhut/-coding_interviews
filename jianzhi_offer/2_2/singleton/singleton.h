class Singleton{
    public:
	static Singleton getInstance(){
	    if( instance == NULL ){
		instance=new Singleton();
	    }
	    return instance
	}

    private:
	Singleton(){ #私有构造函数，防止外部创建该类的实例
	}
	static Singleton instance=NULL;
};
