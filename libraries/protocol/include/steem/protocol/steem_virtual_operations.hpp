#pragma once
#include <steem/protocol/base.hpp>
#include <steem/protocol/block_header.hpp>
#include <steem/protocol/asset.hpp>

#include <fc/utf8.hpp>

namespace steem { namespace protocol {

   struct author_reward_operation : public virtual_operation {
      author_reward_operation(){}
      author_reward_operation( const account_name_type& a, const string& p, const asset& s, const asset& st, const asset& v )
         :author(a), permlink(p), sbd_payout(s), steem_payout(st), vesting_payout(v){}

      account_name_type author;
      string            permlink;
      asset             sbd_payout;
      asset             steem_payout;
      asset             vesting_payout;
   };


   struct curation_reward_operation : public virtual_operation
   {
      curation_reward_operation(){}
      curation_reward_operation( const string& c, const asset& r, const string& a, const string& p )
         :curator(c), reward(r), comment_author(a), comment_permlink(p) {}

      account_name_type curator;
      asset             reward;
      account_name_type comment_author;
      string            comment_permlink;
   };


   struct comment_reward_operation : public virtual_operation
   {
      comment_reward_operation(){}
      comment_reward_operation( const account_name_type& a, const string& pl, const asset& p )
         :author(a), permlink(pl), payout(p){}

      account_name_type author;
      string            permlink;
      asset             payout;
   };


   struct liquidity_reward_operation : public virtual_operation
   {
      liquidity_reward_operation( string o = string(), asset p = asset() )
      :owner(o), payout(p) {}

      account_name_type owner;
      asset             payout;
   };


   struct interest_operation : public virtual_operation
   {
      interest_operation( const string& o = "", const asset& i = asset(0,SBD_SYMBOL) )
         :owner(o),interest(i){}

      account_name_type owner;
      asset             interest;
   };


   struct fill_convert_request_operation : public virtual_operation
   {
      fill_convert_request_operation(){}
      fill_convert_request_operation( const string& o, const uint32_t id, const asset& in, const asset& out )
         :owner(o), requestid(id), amount_in(in), amount_out(out) {}

      account_name_type owner;
      uint32_t          requestid = 0;
      asset             amount_in;
      asset             amount_out;
   };


   struct fill_vesting_withdraw_operation : public virtual_operation
   {
      fill_vesting_withdraw_operation(){}
      fill_vesting_withdraw_operation( const string& f, const string& t, const asset& w, const asset& d )
         :from_account(f), to_account(t), withdrawn(w), deposited(d) {}

      account_name_type from_account;
      account_name_type to_account;
      asset             withdrawn;
      asset             deposited;
   };


   struct shutdown_witness_operation : public virtual_operation
   {
      shutdown_witness_operation(){}
      shutdown_witness_operation( const string& o ):owner(o) {}

      account_name_type owner;
   };


   struct fill_order_operation : public virtual_operation
   {
      fill_order_operation(){}
      fill_order_operation( const string& c_o, uint32_t c_id, const asset& c_p, const string& o_o, uint32_t o_id, const asset& o_p )
      :current_owner(c_o), current_orderid(c_id), current_pays(c_p), open_owner(o_o), open_orderid(o_id), open_pays(o_p) {}

      account_name_type current_owner;
      uint32_t          current_orderid = 0;
      asset             current_pays;
      account_name_type open_owner;
      uint32_t          open_orderid = 0;
      asset             open_pays;
   };


   struct fill_transfer_from_savings_operation : public virtual_operation
   {
      fill_transfer_from_savings_operation() {}
      fill_transfer_from_savings_operation( const account_name_type& f, const account_name_type& t, const asset& a, const uint32_t r, const string& m )
         :from(f), to(t), amount(a), request_id(r), memo(m) {}

      account_name_type from;
      account_name_type to;
      asset             amount;
      uint32_t          request_id = 0;
      string            memo;
   };

   struct hardfork_operation : public virtual_operation
   {
      hardfork_operation() {}
      hardfork_operation( uint32_t hf_id ) : hardfork_id( hf_id ) {}

      uint32_t         hardfork_id = 0;
   };

   struct comment_payout_update_operation : public virtual_operation
   {
      comment_payout_update_operation() {}
      comment_payout_update_operation( const account_name_type& a, const string& p ) : author( a ), permlink( p ) {}

      account_name_type author;
      string            permlink;
   };

   struct return_vesting_delegation_operation : public virtual_operation
   {
      return_vesting_delegation_operation() {}
      return_vesting_delegation_operation( const account_name_type& a, const asset& v ) : account( a ), vesting_shares( v ) {}

      account_name_type account;
      asset             vesting_shares;
   };

   struct comment_benefactor_reward_operation : public virtual_operation
   {
      comment_benefactor_reward_operation() {}
      comment_benefactor_reward_operation( const account_name_type& b, const account_name_type& a, const string& p, const asset& s, const asset& st, const asset& v )
         : benefactor( b ), author( a ), permlink( p ), sbd_payout( s ), steem_payout( st ), vesting_payout( v ) {}

      account_name_type benefactor;
      account_name_type author;
      string            permlink;
      asset             sbd_payout;
      asset             steem_payout;
      asset             vesting_payout;
   };

   struct producer_reward_operation : public virtual_operation
   {
      producer_reward_operation(){}
      producer_reward_operation( const string& p, const asset& v ) : producer( p ), vesting_shares( v ) {}

      account_name_type producer;
      asset             vesting_shares;

   };

   struct clear_null_account_balance_operation : public virtual_operation
   {
      vector< asset >   total_cleared;
   };

   struct sps_fund_operation : public virtual_operation
   {
      sps_fund_operation() {}
      sps_fund_operation( const asset& v ) : additional_funds( v ) {}

      asset additional_funds;
   };

   struct hardfork23_operation : public virtual_operation
   {
      hardfork23_operation() {}
      hardfork23_operation( const account_name_type& acc, const asset& s, const asset& st, const asset& v, const asset& cs )
              : account( acc ), sbd_transferred( s ), steem_transferred( st ), vests_converted( v ), total_steem_from_vests(cs) {}

      account_name_type account;
      asset             sbd_transferred;
      asset             steem_transferred;
      asset             vests_converted; // Amount of converted vests
      asset             total_steem_from_vests; // Resulting STEEM from conversion
   };

} } //steem::protocol

FC_REFLECT( steem::protocol::author_reward_operation, (author)(permlink)(sbd_payout)(steem_payout)(vesting_payout) )
FC_REFLECT( steem::protocol::curation_reward_operation, (curator)(reward)(comment_author)(comment_permlink) )
FC_REFLECT( steem::protocol::comment_reward_operation, (author)(permlink)(payout) )
FC_REFLECT( steem::protocol::fill_convert_request_operation, (owner)(requestid)(amount_in)(amount_out) )
FC_REFLECT( steem::protocol::liquidity_reward_operation, (owner)(payout) )
FC_REFLECT( steem::protocol::interest_operation, (owner)(interest) )
FC_REFLECT( steem::protocol::fill_vesting_withdraw_operation, (from_account)(to_account)(withdrawn)(deposited) )
FC_REFLECT( steem::protocol::shutdown_witness_operation, (owner) )
FC_REFLECT( steem::protocol::fill_order_operation, (current_owner)(current_orderid)(current_pays)(open_owner)(open_orderid)(open_pays) )
FC_REFLECT( steem::protocol::fill_transfer_from_savings_operation, (from)(to)(amount)(request_id)(memo) )
FC_REFLECT( steem::protocol::hardfork_operation, (hardfork_id) )
FC_REFLECT( steem::protocol::comment_payout_update_operation, (author)(permlink) )
FC_REFLECT( steem::protocol::return_vesting_delegation_operation, (account)(vesting_shares) )
FC_REFLECT( steem::protocol::comment_benefactor_reward_operation, (benefactor)(author)(permlink)(sbd_payout)(steem_payout)(vesting_payout) )
FC_REFLECT( steem::protocol::producer_reward_operation, (producer)(vesting_shares) )
FC_REFLECT( steem::protocol::clear_null_account_balance_operation, (total_cleared) )
FC_REFLECT( steem::protocol::sps_fund_operation, (additional_funds) )
FC_REFLECT( steem::protocol::hardfork23_operation, (account)(sbd_transferred)(steem_transferred)(vests_converted)(total_steem_from_vests) )
