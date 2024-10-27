#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static pair<string_view, int> parse1(const string_view &input) {
        const auto idx1 = input.find('(');
        const auto idx2 = input.find(')');
        const auto name = input.substr(0, idx1);
        const auto cntStr = input.substr(idx1 + 1, idx2 - idx1 - 1);
        int cnt;
        std::from_chars(cntStr.data(), cntStr.data() + cntStr.size(), cnt);
        return {name, cnt};
    }

    static pair<string_view, string_view> parse2(const string_view &input) {
        const auto idx = input.find(',');
        auto name1 = input.substr(1, idx - 1);
        auto name2 = input.substr(idx + 1, input.length() - idx - 2);
        return {name1, name2};
    }

public:
    vector<string> trulyMostPopular(const vector<string> &names, vector<string> &synonyms) {
        const auto n = static_cast<int>(names.size());
        auto name2cnt = unordered_map<string_view, int>();
        auto parent = unordered_map<string_view, string_view>();
        for (int i = 0; i < n; ++i) {
            auto [name, cnt] = parse1(names[i]);
            name2cnt[name] = cnt;
            parent[name] = name;
        }

        function<string_view(const string_view &)> find = [&](auto &x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        auto unite = [&](auto &x, auto &y) {
            const auto &px = find(x), &py = find(y);
            if (px != py) {
                if (px < py) {
                    parent[py] = px;
                    name2cnt[px] += name2cnt[py];
                    name2cnt.erase(py);
                } else {
                    parent[px] = py;
                    name2cnt[py] += name2cnt[px];
                    name2cnt.erase(px);
                }
            }
        };

        for (const auto &synonym: synonyms) {
            auto [name1, name2] = parse2(synonym);
            if (parent[name1].empty()) {
                parent[name1] = name1;
            }
            if (parent[name2].empty()) {
                parent[name2] = name2;
            }
            unite(name1, name2);
        }

        auto res = vector<string>();
        for (const auto &[name, cnt]: name2cnt) {
            res.push_back(std::format("{}({})", name, cnt));
        }

        return res;
    }
};

int main() {
    // auto names = vector<string>{"Fcclu(70)", "Ommjh(63)", "Dnsay(60)", "Qbmk(45)", "Unsb(26)", "Gauuk(75)", "Wzyyim(34)", "Bnea(55)", "Kri(71)", "Qnaakk(76)", "Gnplfi(68)", "Hfp(97)", "Qoi(70)", "Ijveol(46)", "Iidh(64)", "Qiy(26)", "Mcnef(59)", "Hvueqc(91)", "Obcbxb(54)", "Dhe(79)", "Jfq(26)", "Uwjsu(41)", "Wfmspz(39)", "Ebov(96)", "Ofl(72)", "Uvkdpn(71)", "Avcp(41)", "Msyr(9)", "Pgfpma(95)", "Vbp(89)", "Koaak(53)", "Qyqifg(85)", "Dwayf(97)", "Oltadg(95)", "Mwwvj(70)", "Uxf(74)", "Qvjp(6)", "Grqrg(81)", "Naf(3)", "Xjjol(62)", "Ibink(32)", "Qxabri(41)", "Ucqh(51)", "Mtz(72)", "Aeax(82)", "Kxutz(5)", "Qweye(15)", "Ard(82)", "Chycnm(4)", "Hcvcgc(97)", "Knpuq(61)", "Yeekgc(11)", "Ntfr(70)", "Lucf(62)", "Uhsg(23)", "Csh(39)", "Txixz(87)", "Kgabb(80)", "Weusps(79)", "Nuq(61)", "Drzsnw(87)", "Xxmsn(98)", "Onnev(77)", "Owh(64)", "Fpaf(46)", "Hvia(6)", "Kufa(95)", "Chhmx(66)", "Avmzs(39)", "Okwuq(96)", "Hrschk(30)", "Ffwni(67)", "Wpagta(25)", "Npilye(14)", "Axwtno(57)", "Qxkjt(31)", "Dwifi(51)", "Kasgmw(95)", "Vgxj(11)", "Nsgbth(26)", "Nzaz(51)", "Owk(87)", "Yjc(94)", "Hljt(21)", "Jvqg(47)", "Alrksy(69)", "Tlv(95)", "Acohsf(86)", "Qejo(60)", "Gbclj(20)", "Nekuam(17)", "Meutux(64)", "Tuvzkd(85)", "Fvkhz(98)", "Rngl(12)", "Gbkq(77)", "Uzgx(65)", "Ghc(15)", "Qsc(48)", "Siv(47)"};
    // auto synonyms = vector<string>{"(Gnplfi,Qxabri)", "(Uzgx,Siv)", "(Bnea,Lucf)", "(Qnaakk,Msyr)", "(Grqrg,Gbclj)", "(Uhsg,Qejo)", "(Csh,Wpagta)", "(Xjjol,Lucf)", "(Qoi,Obcbxb)", "(Npilye,Vgxj)", "(Aeax,Ghc)", "(Txixz,Ffwni)", "(Qweye,Qsc)", "(Kri,Tuvzkd)", "(Ommjh,Vbp)", "(Pgfpma,Xxmsn)", "(Uhsg,Csh)", "(Qvjp,Kxutz)", "(Qxkjt,Tlv)", "(Wfmspz,Owk)", "(Dwayf,Chycnm)", "(Iidh,Qvjp)", "(Dnsay,Rngl)", "(Qweye,Tlv)", "(Wzyyim,Kxutz)", "(Hvueqc,Qejo)", "(Tlv,Ghc)", "(Hvia,Fvkhz)", "(Msyr,Owk)", "(Hrschk,Hljt)", "(Owh,Gbclj)", "(Dwifi,Uzgx)", "(Iidh,Fpaf)", "(Iidh,Meutux)", "(Txixz,Ghc)", "(Gbclj,Qsc)", "(Kgabb,Tuvzkd)", "(Uwjsu,Grqrg)", "(Vbp,Dwayf)", "(Xxmsn,Chhmx)", "(Uxf,Uzgx)"};
    auto names = vector<string>({"John(15)", "Jon(12)", "Chris(13)", "Kris(4)", "Christopher(19)"});
    auto synonyms = vector<string>({"(Jon,John)", "(John,Johnny)", "(Chris,Kris)", "(Chris,Christopher)"});

    auto res = Solution().trulyMostPopular(names, synonyms);
    return 0;
}
