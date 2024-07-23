class Effect {
    public:
        Effect();
        virtual int getAtkModifier() = 0;
        virtual int getDefModifier() = 0;
        virtual ~Effect() = default;
};
